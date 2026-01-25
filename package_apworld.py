"""Package MN64 Rando into an APWorld file."""

import os
import shutil
import subprocess
import sys
import zipfile

# Define paths
temp_mnsg_folder = "temp_mnsg"

# Files and folders to copy into temp mnsg folder
folders_to_copy = ["apworld"]

# Ensure temp mnsg directory exists
os.makedirs(temp_mnsg_folder, exist_ok=True)

# Copy specified folders
for folder in folders_to_copy:
    if os.path.exists(folder):
        # Copy the contents of the folder directly to temp mnsg root
        for item in os.listdir(folder):
            source_path = os.path.join(folder, item)
            dest_path = os.path.join(temp_mnsg_folder, item)
            
            if os.path.isdir(source_path):
                shutil.copytree(source_path, dest_path, dirs_exist_ok=True, ignore=shutil.ignore_patterns("__pycache__"))
            else:
                shutil.copy2(source_path, dest_path)

# Function to zip a folder
def zip_folder(folder_path: str, zip_name: str, preserve_root: bool = False, custom_root_name: str = None):
    """Zip a folder."""
    with zipfile.ZipFile(zip_name, "w", zipfile.ZIP_DEFLATED) as zipf:
        folder_basename = custom_root_name if custom_root_name else os.path.basename(folder_path)
        for root, _, files in os.walk(folder_path):
            for file in files:
                file_path = os.path.join(root, file)
                if preserve_root:
                    arcname = os.path.join(folder_basename, os.path.relpath(file_path, start=folder_path))
                    # Ensures mnsg/ appears only once in zip
                else:
                    arcname = os.path.relpath(file_path, start=folder_path)  # No extra nesting
                zipf.write(file_path, arcname)


# Zip temp mnsg directory
zip_folder(temp_mnsg_folder, "mnsg.apworld", preserve_root=True, custom_root_name="mnsg")
# Delete the temp folder
shutil.rmtree(temp_mnsg_folder)

print("All files have been copied and zipped successfully.")