import pandas as pd
import os

def create_feedback_excel(dataset_path: str):
    # Create a sample feedback DataFrame
    data = {
        'ID': [1],
        'Score': [85],
        'Feedback': ['Sample feedback for testing']
    }
    df = pd.DataFrame(data)
    
    # Save to Excel
    excel_path = os.path.join(dataset_path, 'feedback.xlsx')
    df.to_excel(excel_path, sheet_name='Lab Test 3', index=False)
    print(f"Created feedback.xlsx at {excel_path}")

if __name__ == "__main__":
    dataset_path = os.path.join(os.path.dirname(__file__), 'dataset')
    create_feedback_excel(dataset_path) 