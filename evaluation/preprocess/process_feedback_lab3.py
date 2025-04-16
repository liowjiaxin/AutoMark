import pandas as pd
import numpy as np
import os

# Get the current directory
current_dir = os.path.dirname(os.path.abspath(__file__))
file_path = os.path.join(current_dir, 'Lab3_feedback_fixed.xlsx')  # Use the fixed file

print(f"Loading Excel file: {file_path}")

# Load the Excel file
df = pd.read_excel(file_path, header=0)
print(f"\nDataframe loaded with header=0")
print(f"Shape: {df.shape}")
print(f"Columns: {df.columns.tolist()}")

# Extract the required columns
extracted_data = pd.DataFrame()

# Use the 'ID' column for student_id, first convert to int to remove decimal places
extracted_data['student_id'] = df['ID'].astype(int).astype(str)

# Use 'Subtotal (15)' column for total marks
total_marks_col = 'Subtotal (15)'
print(f"\nUsing column '{total_marks_col}' for total marks")

# Extract total marks, handling potential empty cells or formulas
extracted_data['total_marks'] = pd.to_numeric(df[total_marks_col], errors='coerce')
extracted_data['total_marks'] = extracted_data['total_marks'].fillna(0)

# Calculate total marks scaled to 100%
max_marks = 15.0  # Based on the column name 'Subtotal (15)'
extracted_data['total_marks_100'] = (extracted_data['total_marks'] / max_marks) * 100

# Extract feedback from Q1, Q2, and Q3 columns
print("\nCombining feedback columns to create overall feedback")

# Create one comprehensive feedback string directly
extracted_data['overall_feedback'] = df.apply(
    lambda row: (
        f"Lab 3 Assessment:\n\n"
        f"Q1: {row['Q1'] if not pd.isna(row['Q1']) else 'No feedback available for Q1'}\n\n"
        f"Q2: {row['Q2'] if not pd.isna(row['Q2']) else 'No feedback available for Q2'}\n\n"
        f"Q3: {row['Q3'] if not pd.isna(row['Q3']) else 'No feedback available for Q3'}\n\n"
        f"Overall Score: {pd.to_numeric(row['Subtotal (15)'], errors='coerce') or 0:.1f} out of {max_marks:.1f} "
        f"({(pd.to_numeric(row['Subtotal (15)'], errors='coerce') or 0) / max_marks * 100:.1f}%)"
    ),
    axis=1
)

# Print a sample of the processed data
print("\nSample of processed data (first 5 rows):")
print(extracted_data.head())

# Save to CSV
output_file = os.path.join(current_dir, 'teacher_feedback_lab3.csv')
extracted_data.to_csv(output_file, index=False)

print(f"\nProcessing complete. Data saved to {output_file}")
print(f"Processed {len(extracted_data)} student records") 