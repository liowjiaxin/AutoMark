document.addEventListener('DOMContentLoaded', () => {
    fetchResults();
});

function fetchResults() {
    fetch('/api/results/')
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => {
            populateTable(data.results);
            setupPagination(data.results);
        })
        .catch(error => {
            console.error('Error fetching data:', error);
            alert('An error occurred while fetching the results. Please try again.');
        });
}

function populateTable(data, page = 1, rowsPerPage = 10) {
    const tableBody = document.querySelector('#resultsTable tbody');
    tableBody.innerHTML = '';

    const start = (page - 1) * rowsPerPage;
    const end = start + rowsPerPage;
    const paginatedData = data.slice(start, end);

    paginatedData.forEach(student => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>${student.student_id}</td>
            <td>${student.code_zip_path}</td>
            <td>${student.marks}</td>
            <td>${student.grade}</td>
            <td>${truncateFeedback(formatFeedback(student.feedback))}</td>
        `;
        tableBody.appendChild(row);
    });
}

function truncateFeedback(feedback, maxLength = 100) {
    if (feedback.length > maxLength) {
        const truncated = feedback.substring(0, maxLength) + '...';
        return `<span class="feedback-short">${truncated}</span>
                <span class="feedback-full" style="display:none;">${feedback}</span>
                <a href="#" class="see-more" onclick="toggleFeedback(this); return false;">See more</a>`;
    }
    return feedback;
}

function toggleFeedback(link) {
    const shortFeedback = link.previousElementSibling.previousElementSibling;
    const fullFeedback = link.previousElementSibling;
    if (shortFeedback.style.display === 'none') {
        shortFeedback.style.display = 'inline';
        fullFeedback.style.display = 'none';
        link.textContent = 'See more';
    } else {
        shortFeedback.style.display = 'none';
        fullFeedback.style.display = 'inline';
        link.textContent = 'See less';
    }
}

function formatFeedback(feedback) {
    // Convert **bold text** to <strong>bold text</strong>
    feedback = feedback.replace(/\*\*(.*?)\*\*/g, '<strong>$1</strong>');

    // Convert lists (* item or - item) to <ul><li>item</li></ul>
    feedback = feedback.replace(/(?:^|\n)([*-])\s*(.*?)(?=\n|$)/g, '<ul><li>$2</li></ul>');

    // Convert numbered lists (1. item) to <ol><li>item</li></ol>
    feedback = feedback.replace(/(?:^|\n)(\d+)\.\s*(.*?)(?=\n|$)/g, '<ol><li>$2</li></ol>');

    // Convert line breaks (\n) to <br>
    feedback = feedback.replace(/\n/g, '<br>');

    return feedback;
}

function setupPagination(data, rowsPerPage = 10) {
    const pagination = document.getElementById('pagination');
    pagination.innerHTML = '';

    const pageCount = Math.ceil(data.length / rowsPerPage);
    for (let i = 1; i <= pageCount; i++) {
        const pageButton = document.createElement('button');
        pageButton.textContent = i;
        pageButton.addEventListener('click', () => populateTable(data, i, rowsPerPage));
        pagination.appendChild(pageButton);
    }
}

// Searching Function
function searchStudent() {
    const studentId = document.getElementById('searchInput').value;
    const url = studentId ? `/api/result/${studentId}` : '/api/results';
    
    fetch(url)
        .then(response => {
            if (!response.ok) {
                if (response.status === 404) {
                    return response.json().then(errorDetails => {
                        console.log('Error details:', errorDetails);
                        throw new Error('Result not found');
                    });
                }
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => {
            populateTable(data.results);
            setupPagination(data.results);
        })
        .catch(error => {
            console.error('Error fetching data:', error);
            alert(error.message === 'Result not found' ? `Result for student id ${studentId} not found.` : 'An error occurred while fetching the results. Please try again.');
        });
}

// Sorting Function
function sortTable(column) {
    const table = document.getElementById('resultsTable');
    const rows = Array.from(table.rows).slice(1);
    let compare;

    switch (column) {
        case 'marks':
            compare = (a, b) => b.cells[2].textContent - a.cells[2].textContent;
            break;
        case 'status':
            compare = (a, b) => a.cells[4].textContent.localeCompare(b.cells[4].textContent);
            break;
    }

    rows.sort(compare).forEach(row => table.appendChild(row));
}

// Filtering Function
function filterTable(status) {
    const tableRows = document.querySelectorAll('#resultsTable tbody tr');

    tableRows.forEach(row => {
        const studentStatus = row.cells[4].textContent.toLowerCase();
        if (studentStatus === status) {
            row.style.display = '';
        } else {
            row.style.display = 'none';
        }
    });
}
