import os
import sys
import json
import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore

# Initialize Firebase Admin SDK
cred = credentials.Certificate("D:/Visual Studio Workplace/ESP32 Interface/ESP32 Interface/API/esp32interfaces-firebase-adminsdk-6pogx-af9c61eb4c.json")
firebase_admin.initialize_app(cred)

# Create Firestore client
db = firestore.client()

# Path to the directory containing JSON files
directory = './Data/Info'

# Iterate over each file in the directory
for filename in os.listdir(directory):
    if filename.endswith('.json'):  # Only process JSON files
        filepath = os.path.join(directory, filename)
        
        # Read JSON file
        with open(filepath) as json_file:
            data = json.load(json_file)
        
        # Add document to Firestore collection
        doc_ref = db.collection('UsrInfo').document(filename[:-5])  # Remove '.json' extension from filename
        doc_ref.set(data)
        
        print(f"Uploaded {filename} to Firestore")
