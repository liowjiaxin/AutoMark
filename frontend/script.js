document.getElementById('submit-btn').addEventListener('click', async () => {
    const code = document.getElementById('code-input').value;
    const rubrics = document.getElementById('rubrics').value;
    const studentId = document.getElementById('student-id').value;
    const response = await fetch('/api/grade', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({
            code,
            rubrics,
            student_id: studentId
        })
    });
    const result = await response.json();
    console.log(result)
    document.getElementById('result').innerText = `
    Grade: ${result.grade}
    Feedback: ${result.feedback}
    `;
});