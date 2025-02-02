def format_input(code: str, rubric: str) -> str:
    """
    Format the input for Llama3.2.
    Example: Combine code and rubric into a clear prompt.
    """
    return f"""
    You are a code grading assistant. Evaluate the following code based on the provided rubric:

    Code:
    {code}

    Rubric:
    {rubric}

    Provide a grade and detailed feedback. Give the grade at the last line and prefix it with "Grade:".
    Grades can only be from A to F.
    """

def format_output(model_response: str) -> str:
    """
    Process the raw output from Llama3.2.
    Example: Extract the grade and feedback.
    """
    # Custom logic to parse the response
    if "Grade:" in model_response:
        return model_response.split("Grade:")[1].strip()
    return model_response