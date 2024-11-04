#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>

#include <ESP32Servo.h>

#define RST_PIN 22
#define SS_PIN 5
#define SERVO_PIN 25  // Define the pin where the servo is connected

uint8_t *macAddr[6];


const char* ssid = "Home WiFi";
const char* password = "Giadinh123!";
void printMACAddress();

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
Servo myServo;  // Create a Servo object


void setup() {
	Serial.begin(115200);		// Initialize serial communications with the PC
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(50);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
	myServo.attach(SERVO_PIN);
	printMACAddress();
}

void loop() {
	// // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
	// if ( ! mfrc522.PICC_IsNewCardPresent()) {
	// 	return;
	// }

	// // Select one of the cards
	// if ( ! mfrc522.PICC_ReadCardSerial()) {
	// 	return;
	// }

	// // Dump debug info about the card; PICC_HaltA() is automatically called
	// mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

	// Open the servo (move to 180 degrees)
    // myServo.write(180);
    // delay(3000);  // Wait for 3 seconds
	// Serial.println("Loop");
	// // Close the servo (move to 0 degrees)
    // myServo.write(0);
    // delay(3000);
}

void printMACAddress() {
  uint8_t mac[6];
  WiFi.macAddress(mac);

  Serial.print("MAC address: ");
  for (int i = 0; i < 6; i++) {
    if (mac[i] < 0x10) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
  }
  Serial.println();
}

