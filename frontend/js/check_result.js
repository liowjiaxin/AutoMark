document.addEventListener('DOMContentLoaded', () => {
    fetchResults();
});

function fetchResults() {
    fetch('/api/student-results')
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => populateTable(data))
        .catch(error => {
            console.error('Error fetching data:', error);
            alert('An error occurred while fetching the results. Please try again.');
        });
}

function populateTable(data) {
    const tableBody = document.querySelector('#resultsTable tbody');
    tableBody.innerHTML = '';

    data.forEach(student => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>${student.id}</td>
            <td>${student.name}</td>
            <td>${student.subject}</td>
            <td>${student.marks}</td>
            <td>${student.grade}</td>
            <td class="${student.status === 'Pass' ? 'status-pass' : 'status-fail'}">${student.status}</td>
        `;
        tableBody.appendChild(row);
    });
}

// Searching Function
function searchStudent() {
    const searchInput = document.getElementById('searchInput').value.toLowerCase();
    const tableRows = document.querySelectorAll('#resultsTable tbody tr');
    let studentFound = false;

    tableRows.forEach(row => {
        const studentId = row.cells[0].textContent.toLowerCase();
        if (studentId.includes(searchInput)) {
            row.style.display = '';
            studentFound = true;
        } else {
            row.style.display = 'none';
        }
    });

    if (!studentFound) {
        alert("Student ID does not exist.");
    }
}

// Sorting Function
function sortTable(column) {
    const table = document.getElementById('resultsTable');
    const rows = Array.from(table.rows).slice(1);
    let compare;

    switch (column) {
        case 'name':
            compare = (a, b) => a.cells[1].textContent.localeCompare(b.cells[1].textContent);
            break;
        case 'marks':
            compare = (a, b) => b.cells[3].textContent - a.cells[3].textContent;
            break;
        case 'status':
            compare = (a, b) => a.cells[5].textContent.localeCompare(b.cells[5].textContent);
            break;
    }

    rows.sort(compare).forEach(row => table.appendChild(row));
}

// Filtering Function
function filterTable(status) {
    const tableRows = document.querySelectorAll('#resultsTable tbody tr');

    tableRows.forEach(row => {
        const studentStatus = row.cells[5].textContent.toLowerCase();
        if (studentStatus === status) {
            row.style.display = '';
        } else {
            row.style.display = 'none';
        }
    });
}
