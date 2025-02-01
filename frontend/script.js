document.getElementById('submit-btn').addEventListener('click', async () => {
    const code = document.getElementById('code-input').value;
    const response = await fetch('/api/grade', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({ code })
    });
    const result = await response.json();
    document.getElementById('result').innerText = `Grade: ${result.grade}`;
});