import os
import face_recognition
import numpy as np
from firebase_admin import credentials, initialize_app, storage
import time

known_face_encodings = []
known_face_names = []
images_dir = os.path.join(".", "Data", "Img")
results_file = "learning_results.txt"

# Initialize Firebase app
cred = credentials.Certificate("D:/Visual Studio Workplace/ESP32 Interface/ESP32 Interface/API/esp32interfaces-firebase-adminsdk-6pogx-af9c61eb4c.json")
initialize_app(cred, {'storageBucket': 'esp32interfaces.appspot.com'})

# Clear the results file if it exists
open(results_file, 'w').close()

# Start timing the learning process
start_time = time.time()

for person in os.listdir(images_dir):
    person_dir = os.path.join(images_dir, person)
    if os.path.isdir(person_dir):
        print(f"Processing folder: {person}")
        successful = 0
        failed = 0
        
        for file in os.listdir(person_dir):
            print(f"Processing image: {file}")
            image_path = os.path.join(person_dir, file)
            image = face_recognition.load_image_file(image_path)
            try:
                known_face_encodings.append(face_recognition.face_encodings(image)[0])
                known_face_names.append(person)
                successful += 1
                print('Success')
            except IndexError:
                print(f"{file} - ERROR: No face detected")
                os.remove(image_path)
                failed += 1
        
        # Calculate total learns
        total_learns = successful + failed
        
        # Write results for this person to the file
        with open(results_file, 'a') as f:
            f.write(f"{person}:\n")
            f.write(f"  Total learns: {total_learns}\n")
            f.write(f"  Successful learns: {successful}\n")
            f.write(f"  Failed learns: {failed}\n")
            if total_learns > 0:
                success_rate = successful / total_learns
                f.write(f"  Success rate: {success_rate:.2%}\n")
            f.write("\n")

np.savetxt("encoding.txt", known_face_encodings)
np.savetxt("encodingname.txt", known_face_names, delimiter=" ", fmt="%s")

# End timing the learning process
end_time = time.time()
learning_time = end_time - start_time

print("\nLearning process completed.")
print("-" * 40)

# Print the contents of the results file
with open(results_file, 'r') as f:
    print(f.read())
    
    
print("\n",learning_time)
print("-" * 40)
# After creating the files, upload them to Firebase Storage
bucket = storage.bucket()

files_to_upload = ["encoding.txt", "encodingname.txt", "learning_results.txt"]

for file_name in files_to_upload:
    blob = bucket.blob(file_name)
    blob.upload_from_filename(file_name)
    print(f"File {file_name} uploaded to Firebase Storage.")

print("\nAll files uploaded to Firebase Storage.")