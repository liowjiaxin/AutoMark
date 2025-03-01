document.addEventListener('DOMContentLoaded', () => {
    fetchResults();
    document.getElementById("submit-assignment").addEventListener("click", submitAssignment);
});

function submitAssignment() {
    const studentId = document.getElementById("student-id").value;
    const language = document.getElementById("language").value;
    const compiler = document.getElementById("compiler").value;
    const commands = document.getElementById("commands").value;
    const studentAnswerZipFilename = document.getElementById("student-answer-zip-filename").value;
    const markingSchemeFilename = document.getElementById("marking-scheme-filename").value;

    const data = {
        student_id: studentId,
        language,
        compiler,
        commands,
        code_zip_filename: studentAnswerZipFilename,
        marking_scheme_filename: markingSchemeFilename
    }

    fetch("/api/grade", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify(data)
    })
    .then(response => response.json())
    .then(data => {
        document.getElementById("result").innerText = JSON.stringify(data, null, 2);
    })
    .catch(error => console.error("Error:", error));
}

Dropzone.options.markingSchemeDropzone = {
    paramName: "file",
    maxFilesize: 20, // MB
    success: function(file, response) {
        console.log("File uploaded successfully:", response.info);
        document.getElementById("marking-scheme-filename").value = response.filename;
    },
    error: function(file, response) {
        console.error("File upload error:", response);
    }
};

Dropzone.options.studentAnswerDropzone = {
    paramName: "file",
    maxFilesize: 20, // MB
    success: function(file, response) {
        console.log("File uploaded successfully:", response.info);
        document.getElementById("student-answer-zip-filename").value = response.filename;
    },
    error: function(file, response) {
        console.error("File upload error:", response);
    }
};

function fetchResults() {
    // Fetch data from the backend (replace with actual backend API)
    fetch('https://api.example.com/student-results')
        .then(response => response.json())
        .then(data => populateTable(data))
        .catch(error => console.error('Error fetching data:', error));
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

function searchStudent() {
    const searchInput = document.getElementById('searchInput').value.toLowerCase();
    const tableRows = document.querySelectorAll('#resultsTable tbody tr');

    tableRows.forEach(row => {
        const studentId = row.cells[0].textContent.toLowerCase();
        if (studentId.includes(searchInput)) {
            row.style.display = '';
        } else {
            row.style.display = 'none';
        }
    });
}

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
