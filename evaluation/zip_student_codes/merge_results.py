import pandas as pd
import os

# Read the CSV files
teacher_df = pd.read_csv('../preprocess/teacher_feedback_lab3_fixed.csv', 
                        names=['student_id', 'teacher_marks_15', 'teacher_marks_100', 'teacher_feedback'])
ai_df = pd.read_csv('evaluation_results.csv')

# Clean up the data
teacher_df['student_id'] = teacher_df['student_id'].astype(str)
ai_df['student_id'] = ai_df['student_id'].astype(str)

# Remove rows where ai_feedback is missing, empty, or generic errors
df_cleaned = ai_df[
    ai_df['feedback'].notna() &
    ai_df['feedback'].str.strip().ne("") &
    ai_df['feedback'].str.lower().ne("n/a") &
    ai_df['feedback'].str.lower().ne("no submission")
]

# Merge the dataframes
merged_df = pd.merge(teacher_df, df_cleaned, on='student_id', how='outer')

# Select and rename columns
result_df = merged_df[['student_id', 
                      'teacher_marks_15', 
                      'marks_15', 
                      'teacher_feedback', 
                      'feedback']]

# Rename columns for clarity
result_df.columns = ['id', 
                    'teacher_marks', 
                    'ai_marks', 
                    'teacher_feedback', 
                    'ai_feedback']

# Save to CSV
result_df.to_csv('merged_grading_results.csv', index=False)
print("Merged results saved to merged_grading_results.csv") 