document.addEventListener('DOMContentLoaded', () => {
  fetchResults();
  document.getElementById("submit-assignment").addEventListener("click", submitAssignment);
});

document.addEventListener('DOMContentLoaded', () => {
  const languageSelect = document.getElementById('language');
  const versionSelect = document.getElementById('version');

  const pythonVersions = ['3.9', '3.10', '3.11', '3.12', '3.13'];

  languageSelect.addEventListener('change', () => {
    const selectedLanguage = languageSelect.value;
    versionSelect.innerHTML = '';

    if (selectedLanguage === 'Python') {
      versionSelect.disabled = false;
      pythonVersions.forEach(version => {
        const option = document.createElement('option');
        option.value = version;
        option.textContent = version;
        versionSelect.appendChild(option);
      });
    } else {
      versionSelect.disabled = true;
      const option = document.createElement('option');
      option.value = '-';
      option.textContent = '-';
      versionSelect.appendChild(option);
    }
  });

  // Trigger change event to set initial state
  languageSelect.dispatchEvent(new Event('change'));
  versionSelect.value = '-'; // Set default version
});

function submitAssignment() {
  const studentId = document.getElementById("student-id").value;
  const language = document.getElementById("language").value;
  const version = document.getElementById("version").value;
  const studentAnswerZipFilename = document.getElementById("student-answer-zip-filename").value;
  const markingSchemeFilename = document.getElementById("marking-scheme-filename").value;

  if (!language || language === '-') {
    alert("Please select a language.");
    return;
  }

  if (!version || version === '-') {
    alert("Please select a version.");
    return;
  }

  if (!markingSchemeFilename) {
    alert("Please upload the marking scheme.");
    return;
  }

  if (!studentAnswerZipFilename) {
    alert("Please upload the student's answer.");
    return;
  }

  if (!studentId) {
    alert("Please enter the student ID.");
    return;
  }

  const data = {
    student_id: studentId,
    language,
    version,
    code_zip_filename: studentAnswerZipFilename,
    marking_scheme_filename: markingSchemeFilename
  };

  fetch("/api/grade", {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify(data)
  })
    .then(response => {
      if (!response.ok) {
        throw new Error('Network response was not ok');
      }
      return response.json();
    })
    .then(data => {
      document.getElementById("result").innerText = JSON.stringify(data, null, 2);
    })
    .catch(error => {
      console.error("Error:", error);
      alert("An error occurred while submitting the assignment. Please try again.");
    });
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
    alert("An error occurred while uploading the marking scheme. Please try again.");
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
    alert("An error occurred while uploading the student's answer. Please try again.");
  }
};

function fetchResults() {
  // Fetch data from the backend (replace with actual backend API)
  fetch('https://api.example.com/student-results')
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
