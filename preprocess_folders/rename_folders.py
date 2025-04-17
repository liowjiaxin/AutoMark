import os
import shutil
import pandas as pd
from rapidfuzz import fuzz, process

# === CONFIGURATION ===
feedback_file = "Lab assessment 1.xlsx"
submission_folder = "lab1_submissions"
manual_override_file = "manual_override_template.csv"
sheet_index = 0
test_mode = False   # Set to True to preview
test_limit = 5
fuzzy_threshold = 85

# === Step 1: Load and clean student data ===
df = pd.read_excel(feedback_file, sheet_name=sheet_index)
df_students = df.iloc[3:, [1, 2]]
df_students.columns = ['StudentID', 'Name']
df_students = df_students.dropna()
df_students['StudentID'] = df_students['StudentID'].astype(str).str.split('.').str[0]

def normalize_name(name):
    return str(name).lower().replace("-", "").replace(" ", "").strip()

# === Step 2: Create name→ID map with reversed support
name_to_id = {}
name_variants = []

for _, row in df_students.iterrows():
    student_id = row['StudentID']
    name = row['Name']
    if pd.notnull(name):
        parts = name.strip().split()
        normal = normalize_name(name)
        reversed_order = normalize_name(" ".join(parts[::-1]))
        name_to_id[normal] = student_id
        name_to_id[reversed_order] = student_id
        name_variants.extend([normal, reversed_order])

# === Step 3: Load manual override CSV if exists
manual_override_map = {}
if os.path.exists(manual_override_file):
    manual_df = pd.read_csv(manual_override_file)
    for _, row in manual_df.iterrows():
        folder_name = str(row['Unmatched Folder'])
        folder_normalized = folder_name.split("_")[0].lower().replace("-", "").replace(" ", "").strip()
        student_id = str(row['Student ID'])
        manual_override_map[folder_normalized] = student_id

# === Step 4: Rename folders
folder_count = 0
unmatched = []

for folder in os.listdir(submission_folder):
    if test_mode and folder_count >= test_limit:
        break

    folder_path = os.path.join(submission_folder, folder)
    if os.path.isdir(folder_path):
        if folder.isdigit():
            continue

        folder_clean = folder.replace("_assignsubmission_file", "")
        name_raw = "_".join(folder_clean.split("_")[:-1]) if "_" in folder_clean else folder_clean
        name_part = normalize_name(name_raw)

        # Priority 1: Manual override
        student_id = manual_override_map.get(name_part)

        # Priority 2: Exact match
        if not student_id:
            student_id = name_to_id.get(name_part)

        # Priority 3: Fuzzy match
        if not student_id:
            match, score, _ = process.extractOne(name_part, name_variants, scorer=fuzz.partial_ratio)
            if score >= fuzzy_threshold:
                student_id = name_to_id[match]

        # Rename if matched
        if student_id:
            new_folder_path = os.path.join(submission_folder, student_id)

            if os.path.exists(new_folder_path):
                print(f"Overwriting existing folder: {student_id}")
                if not test_mode:
                    shutil.rmtree(new_folder_path)

            if test_mode:
                print(f"[TEST] Would rename: {folder} → {student_id}")
            else:
                print(f"Renaming: {folder} → {student_id}")
                os.rename(folder_path, new_folder_path)

            folder_count += 1
        else:
            print(f"No match found for folder: {folder}")
            unmatched.append(folder)

# === Step 5: Save unmatched list
if unmatched:
    pd.DataFrame(unmatched, columns=["Unmatched Folder"]).to_csv("unmatched_folders.csv", index=False)
    print("Unmatched folders saved to unmatched_folders.csv")
