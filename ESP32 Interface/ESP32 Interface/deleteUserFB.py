import sys
import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore
import os
from google.cloud import storage


# Set the path to your service account JSON key file
os.environ["GOOGLE_APPLICATION_CREDENTIALS"] = "D:/Visual Studio Workplace/ESP32 Interface/ESP32 Interface/API/esp32interfaces-firebase-adminsdk-6pogx-af9c61eb4c.json"

# Specify the local directory path and GCS bucket name
gcs_bucket_name = "esp32interfaces.appspot.com"


# Replace with the path to your service account key file
cred = credentials.Certificate("D:/Visual Studio Workplace/ESP32 Interface/ESP32 Interface/API/esp32interfaces-firebase-adminsdk-6pogx-af9c61eb4c.json")

# Initialize the Firebase Admin SDK
firebase_admin.initialize_app(cred, {
        'storageBucket': 'esp32interfaces.appspot.com'  # Replace 'your-storage-bucket-name' with your Firebase Storage bucket name
    })

# Get a reference to the Firestore database
db = firestore.client()

def delete_file_from_firestore(user_id):
    # Get a reference to the Firestore collection
    collection_ref = db.collection('UsrInfo')

    # Construct a query to find the document with the matching user_id
    query = collection_ref.where('id', '==', user_id)

    # Get the matching documents
    docs = query.stream()

    # Delete the matching documents
    for doc in docs:
        doc.reference.delete()

    print(f"Successfully deleted file for user ID: {user_id} from Firestore")

def delete_user_folder(user_name):
    # Initialize Firebase Admin SDK (only if it's not already initialized)
    if not firebase_admin._apps:
        cred = credentials.Certificate('D:/Visual Studio Workplace/ESP32 Interface/ESP32 Interface/API/esp32interfaces-firebase-adminsdk-6pogx-af9c61eb4c.json')  # Replace 'path/to/serviceAccountKey.json' with the actual path to your service account key file
        firebase_admin.initialize_app(cred, {
            'storageBucket': 'esp32interfaces.appspot.com'  # Replace 'your-storage-bucket-name' with your Firebase Storage bucket name
        })

    # Get a reference to the default storage bucket
    bucket = storage.bucket()

    folder_prefix = user_name + '/'

    # List all files in the folder
    blobs = bucket.list_blobs(prefix=folder_prefix)
    file_count = 0

    # Delete each file in the folder
    for blob in blobs:
        blob.delete()
        file_count += 1

    if file_count > 0:
        print(f"{file_count} file(s) deleted in folder '{user_name}'.")
    else:
        print(f"Folder '{user_name}' does not exist or is already empty.")


# Extract the command-line arguments
user_id = sys.argv[1]
# user_name = sys.argv[1] + " " + sys.argv[2] + " " + sys.argv[3]
# if len(sys.argv) > 4:
#     user_name += " " + sys.argv[4]


print(user_id)
#print(user_name)
# Call the delete_user_by_id function with the provided user_id
delete_file_from_firestore(user_id)

# Call the delete_folder_from_gcs function with the provided username
# delete_user_folder(user_name)