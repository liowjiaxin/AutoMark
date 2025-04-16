import pandas as pd
import numpy as np
import tensorflow as tf
import tensorflow_hub as hub
from pathlib import Path
import os

def load_bleurt_model():
    """Load the BLEURT-20 model from the checkpoint."""
    checkpoint = "bleurt/BLEURT-20"
    if not os.path.exists(checkpoint):
        raise FileNotFoundError(f"BLEURT-20 checkpoint not found at {checkpoint}. Please download it first.")
    
    return hub.load(checkpoint)

def calculate_bleurt_score(model, reference, candidate):
    """Calculate BLEURT score between reference and candidate text."""
    scores = model.signatures["predict"](
        tf.constant([reference]),
        tf.constant([candidate])
    )["predictions"]
    return float(scores[0])

def compare_feedback(input_file, output_file):
    """Compare AI feedback and teacher feedback from the input file."""
    # Load the BLEURT model
    print("Loading BLEURT-20 model...")
    bleurt_model = load_bleurt_model()
    
    # Read the input file
    print(f"Reading input file: {input_file}")
    df = pd.read_csv(input_file)
    
    # Initialize results list
    results = []
    
    # Process each row
    print("Comparing feedback...")
    for idx, row in df.iterrows():
        teacher_feedback = str(row['teacher_feedback'])
        ai_feedback = str(row['ai_feedback'])
        
        # Skip if either feedback is empty or NaN
        if pd.isna(teacher_feedback) or pd.isna(ai_feedback) or teacher_feedback.strip() == "" or ai_feedback.strip() == "":
            continue
        
        # Calculate BLEURT score
        score = calculate_bleurt_score(bleurt_model, teacher_feedback, ai_feedback)
        
        # Add to results
        results.append({
            'student_id': row['id'],
            'teacher_marks': row['teacher_marks'],
            'ai_marks': row['ai_marks'],
            'teacher_feedback': teacher_feedback,
            'ai_feedback': ai_feedback,
            'bleurt_score': score
        })
        
        if (idx + 1) % 10 == 0:
            print(f"Processed {idx + 1} rows...")
    
    # Create results dataframe
    results_df = pd.DataFrame(results)
    
    # Save results
    print(f"Saving results to {output_file}")
    results_df.to_csv(output_file, index=False)
    print("Done!")

if __name__ == "__main__":
    # Set input and output file paths
    input_file = "merged_grading_results.csv"  # Using the merged results file
    output_file = "feedback_comparison_results.csv"
    
    # Run the comparison
    compare_feedback(input_file, output_file) 