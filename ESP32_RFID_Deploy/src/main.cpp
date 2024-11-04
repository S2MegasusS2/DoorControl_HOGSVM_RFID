#include <Arduino.h>

#include <SPI.h>
#include <MFRC522.h>

#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <time.h>
#include <ArduinoJson.h>

#include <ESP32Servo.h>

#define LED_PIN 2

// ==============================================================================================================================================
// MRC522 setup
#define RST_PIN         22        
#define SS_PIN          5         
MFRC522 mfrc522(SS_PIN, RST_PIN);        // instatiate a MFRC522 reader object.
MFRC522::MIFARE_Key key;//create a MIFARE_Key struct named 'key', which will hold the card information
int writeBlock(int blockNumber, byte arrayAddress[]);
int readBlock(int blockNumber, byte arrayAddress[]);

// ==============================================================================================================================================
// Wifi setup
#define WIFI_SSID "Home WiFi"
#define WIFI_PASSWORD "Giadinh123!"
const char* ssid = "Home WiFi";
const char* password = "Giadinh123!";

// ==============================================================================================================================================
// Firebase setup
#define API_KEY "AIzaSyCQzttW6gc8zgNUV5Q4F9ttt_CLJebkG2w"
#define FIREBASE_PROJECT_ID "esp32interfaces"
#define USER_EMAIL "lovelytiger7798@gmail.com"
#define USER_PASSWORD "NguyenVanBe123!@#"

FirebaseData Fbdo;
FirebaseAuth Auth;
FirebaseConfig Config;

String documentPath = "House/Room_1";

void sendToFirestoreDatabase(String &currTime, FirebaseJson &fb_js);

// ==============================================================================================================================================
// Servo setup
Servo myServo;
int servoPin = 25;

// ==============================================================================================================================================
// Real-time setup
const char* ntpServer = "asia.pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 7 * 3600;  // GMT+7:00
void printLocalTime(tm* timeInfo);
String getFormattedTimeStr(tm* timeInfo);
struct tm timeinfo;

int block=2;//this is the block number we will write into and then read. Do not write into 'sector trailer' block, since this can make the block unusable.
                          
//byte blockcontent[16] = {"pcbreflux......"};//an array with 16 bytes to be written into one of the 64 card blocks is defined!!
//byte blockcontent[16] = {"0CDC7E616ECC"};//an array with 16 bytes to be written into one of the 64 card blocks is defined!!
byte blockcontent[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//all zeros. This can be used to delete a block.
byte readbackblock[18];//This array is used for reading out a block. The MIFARE_Read method requires a buffer that is at least 18 bytes to hold the 16 bytes of a block.






// ==============================================================================================================================================
// Define MAC variables
byte macAddr[6];
char MAC_ADDRESS[13];

void setup() {
	Serial.begin(115200);        // Initialize serial communications with the PC
  delay(1000);

  // ==============================================================================================================================================
  // Init WiFi for ESP32

  WiFi.disconnect();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  WiFi.macAddress(macAddr);   // Get MAC address from ESP32
  sprintf(MAC_ADDRESS, "%02X%02X%02X%02X%02X%02X", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
  Serial.print("ESP32 macAddr: ");
  Serial.println(MAC_ADDRESS);


  // ==============================================================================================================================================
  // Init Firebase
  // Assign API key
  Config.api_key = API_KEY;

  // Assign user sign-in credentials
  Auth.user.email = USER_EMAIL;
  Auth.user.password = USER_PASSWORD;

  // Assign callback function for long-running token generation task
  Config.token_status_callback = tokenStatusCallback;

  // Begin Firebase
  Firebase.begin(&Config, &Auth);

  // Reconnect to WiFi
  Firebase.reconnectWiFi(true);
  Serial.print("ESP32 macAddr: ");
  Serial.println(MAC_ADDRESS);


  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card (in case you wonder what PCD means: proximity coupling device)
  // Initialize default key for access RFID
	for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;//keyByte is defined in the "MIFARE_Key" 'struct' definition in the .h file of the library
  }

  // ==============================================================================================================================================
  // Setup current time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  Serial.println(getFormattedTimeStr(&timeinfo));
  // Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  // Serial.print("Day of week: ");
  // Serial.println(&timeinfo, "%A");
  // Serial.print("Month: ");
  // Serial.println(&timeinfo, "%B");
  // Serial.print("Day of Month: ");
  // Serial.println(&timeinfo, "%d");
  // Serial.print("Year: ");
  // Serial.println(&timeinfo, "%Y");
  // Serial.print("Hour: ");
  // Serial.println(&timeinfo, "%H");
  // Serial.print("Hour (12 hour format): ");
  // Serial.println(&timeinfo, "%I");
  // Serial.print("Minute: ");
  // Serial.println(&timeinfo, "%M");
  // Serial.print("Second: ");
  // Serial.println(&timeinfo, "%S");


  // ==============================================================================================================================================
  // Setup Servo
  myServo.attach(servoPin);
  myServo.write(180);
}

void loop() {
  Serial.println("Fiding RFID Card...");
  if ( ! mfrc522.PICC_IsNewCardPresent()) {     //if PICC_IsNewCardPresent returns 1, a new card has been found and we continue
    delay(1000);
    return;                                     //if it did not find a new card is returns a '0' and we return to the start of the loop
  }
  Serial.println("Card Found!");
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {       //if PICC_ReadCardSerial returns 1, the "uid" struct (see MFRC522.h lines 238-45)) contains the ID of the read card.
    mfrc522.PCD_Init();                         // Init MFRC522 card
    return;                                     //if it returns a '0' something went wrong and we return to the start of the loop
  }

  FirebaseJson content;

  readBlock(block, readbackblock);              //read the block back

  Serial.print("Data in RFID Card: ");
  for (int i=0 ; i<16 ; i++)                    //print the block contents
  {
    char character = char(readbackblock[i]);
    Serial.print(character);
  }
  Serial.println("");

  // Convert readbackblock into a character array
  char dataRFID[17];
  for (int j=0 ; j<16 ; j++)                    
  {
    sprintf(&dataRFID[j], "%c", readbackblock[j]);
  }
  dataRFID[16] = '\0';
  Serial.print("MAC ADDRESS: ");
  Serial.println(MAC_ADDRESS);

  // If scanning RFID correctly, send info to Firebase
  if (strncmp(MAC_ADDRESS, dataRFID, 12) == 0)
  {
    Serial.println("ID MATCH!");
    myServo.write(0);
    String currTime = getFormattedTimeStr(&timeinfo);
    sendToFirestoreDatabase(currTime, content);
    Serial.println(currTime);
    delay(5000);
    myServo.write(180);
    }
  else
  {
    Serial.println("ID NOT MATCH!");
  }
  delay(2000);
  mfrc522.PCD_Init();        // Init MFRC522 card (in case you wonder what PCD means: proximity coupling device)
}


// ===================================================================================================================================
// User function 

#pragma region writeBlock
// int writeBlock(int blockNumber, byte arrayAddress[]) 
// {
//   //this makes sure that we only write into data blocks. Every 4th block is a trailer block for the access/security info.
//   int largestModulo4Number=blockNumber/4*4;
//   int trailerBlock=largestModulo4Number+3;//determine trailer block for the sector
//   if (blockNumber > 2 && (blockNumber+1)%4 == 0){Serial.print(blockNumber);Serial.println(" is a trailer block:");return 2;}//block number is a trailer block (modulo 4); quit and send error code 2
//   Serial.print(blockNumber);
//   Serial.println(" is a data block:");
  
//   /*****************************************authentication of the desired block for access***********************************************************/
//   MFRC522::StatusCode status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
//   //byte PCD_Authenticate(byte command, byte blockAddr, MIFARE_Key *key, Uid *uid);
//   //this method is used to authenticate a certain block for writing or reading
//   //command: See enumerations above -> PICC_CMD_MF_AUTH_KEY_A = 0x60 (=1100000),    // this command performs authentication with Key A
//   //blockAddr is the number of the block from 0 to 15.
//   //MIFARE_Key *key is a pointer to the MIFARE_Key struct defined above, this struct needs to be defined for each block. New cards have all A/B= FF FF FF FF FF FF
//   //Uid *uid is a pointer to the UID struct that contains the user ID of the card.
//   if (status != MFRC522::STATUS_OK) {
//          Serial.print("PCD_Authenticate() failed: ");
//          Serial.println(mfrc522.GetStatusCodeName(status));
//          return 3;//return "3" as error message
//   }
//   //it appears the authentication needs to be made before every block read/write within a specific sector.
//   //If a different sector is being authenticated access to the previous one is lost.


//   /*****************************************writing the block***********************************************************/
        
//   status = mfrc522.MIFARE_Write(blockNumber, arrayAddress, 16);//valueBlockA is the block number, MIFARE_Write(block number (0-15), byte array containing 16 values, number of bytes in block (=16))
//   //status = mfrc522.MIFARE_Write(9, value1Block, 16);
//   if (status != MFRC522::STATUS_OK) {
//            Serial.print("MIFARE_Write() failed: ");
//            Serial.println(mfrc522.GetStatusCodeName(status));
//            return 4;//return "4" as error message
//   }
//   Serial.println("block was written");

//   return 0;
// }
#pragma endregion
#pragma region readBlock
int readBlock(int blockNumber, byte arrayAddress[]) 
{
  int largestModulo4Number=blockNumber/4*4;
  int trailerBlock=largestModulo4Number+3;//determine trailer block for the sector

  /*****************************************authentication of the desired block for access***********************************************************/
  MFRC522::StatusCode status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  //byte PCD_Authenticate(byte command, byte blockAddr, MIFARE_Key *key, Uid *uid);
  //this method is used to authenticate a certain block for writing or reading
  //command: See enumerations above -> PICC_CMD_MF_AUTH_KEY_A = 0x60 (=1100000),    // this command performs authentication with Key A
  //blockAddr is the number of the block from 0 to 15.
  //MIFARE_Key *key is a pointer to the MIFARE_Key struct defined above, this struct needs to be defined for each block. New cards have all A/B= FF FF FF FF FF FF
  //Uid *uid is a pointer to the UID struct that contains the user ID of the card.
  if (status != MFRC522::STATUS_OK) {
         Serial.print("PCD_Authenticate() failed (read): ");
         Serial.println(mfrc522.GetStatusCodeName(status));
         return 3;//return "3" as error message
  }
  //it appears the authentication needs to be made before every block read/write within a specific sector.
  //If a different sector is being authenticated access to the previous one is lost.


  /*****************************************reading a block***********************************************************/
        
  byte buffersize = 18;//we need to define a variable with the read buffer size, since the MIFARE_Read method below needs a pointer to the variable that contains the size... 
  status = mfrc522.MIFARE_Read(blockNumber, arrayAddress, &buffersize);//&buffersize is a pointer to the buffersize variable; MIFARE_Read requires a pointer instead of just a number
  if (status != MFRC522::STATUS_OK) {
          Serial.print("MIFARE_read() failed: ");
          Serial.println((const char*)mfrc522.GetStatusCodeName(status));
          return 4;//return "4" as error message
  }
  Serial.println("block was read");

  return 0;
}
#pragma endregion
#pragma region getFormattedTimeStr

String getFormattedTimeStr(tm* timeInfo)
{
  if (!getLocalTime(timeInfo)) {
    Serial.println("Failed to obtain time");
  }
  char timeBuffer[50];
  strftime(timeBuffer, sizeof(timeBuffer), "%A, %B, %d %Y %H:%M:%S", timeInfo);
  return String(timeBuffer);
}
#pragma endregion
#pragma region sendToFirestoreDatabase

void sendToFirestoreDatabase(String &currTime, FirebaseJson &fb_js)
{
  Serial.println("Starting to send!");
  fb_js.set("fields/User/stringValue", "");
  fb_js.set("fields/Time/stringValue", currTime);
  fb_js.set("fields/Type/stringValue", "Scan RFID");
  Serial.println("Setup done!");
  if (Firebase.Firestore.patchDocument(&Fbdo, FIREBASE_PROJECT_ID, "", documentPath.c_str(), fb_js.raw(), "User,Time,Type"))
  {
    Serial.printf("ok\n%s\n\n", Fbdo.payload().c_str());
    return;
  }
  else
  {
    Serial.println(Fbdo.errorReason());
  }

  if (Firebase.Firestore.createDocument(&Fbdo, FIREBASE_PROJECT_ID, "", documentPath.c_str(), fb_js.raw()))
  {
    Serial.printf("ok\n%s\n\n", Fbdo.payload().c_str());
    return;
  }
  else
  {
    Serial.println(Fbdo.errorReason());
  }
  delay(5000);
}

#pragma endregion
