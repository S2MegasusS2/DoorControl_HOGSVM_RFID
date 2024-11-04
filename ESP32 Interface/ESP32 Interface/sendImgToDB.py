import os
from google.cloud import storage

# Set the path to your service account JSON key file
os.environ["GOOGLE_APPLICATION_CREDENTIALS"] = "D:/Visual Studio Workplace/ESP32 Interface/ESP32 Interface/API/esp32interfaces-firebase-adminsdk-6pogx-af9c61eb4c.json"

# Specify the local directory path and GCS bucket name
local_directory = "./Data/Img"
gcs_bucket_name = "esp32interfaces.appspot.com"

def upload_directory_to_gcs(local_directory, gcs_bucket_name):
    # Create a storage client
    client = storage.Client()

    # Get the bucket
    bucket = client.get_bucket(gcs_bucket_name)

    # Iterate over files in the local directory
    for root, directories, files in os.walk(local_directory):
        for filename in files:
            local_file_path = os.path.join(root, filename)

            # Create a blob object in the bucket
            gcs_blob_name = os.path.join(os.path.relpath(root, local_directory), filename)
            blob = bucket.blob(gcs_blob_name)

            # Upload the local file to the blob
            blob.upload_from_filename(local_file_path)

            print(f"File {local_file_path} uploaded to {gcs_bucket_name}/{gcs_blob_name} successfully.")


upload_directory_to_gcs(local_directory, gcs_bucket_name)