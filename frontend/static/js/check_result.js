document.addEventListener("DOMContentLoaded", () => {
    fetchResults();
});

async function fetchResults() {
    try {
        const response = await fetch("/api/results/");
        if (!response.ok) throw new Error("Network response was not ok");
        
        const data = await response.json();
        populateTable(data.results);
        displayTablePage(1); // Ensure pagination is correctly applied
    } catch (error) {
        console.error("Error fetching data:", error);
        alert("An error occurred while fetching the results. Please try again.");
    }
}

function populateTable(data) {
    const tableBody = document.querySelector("#resultsTable tbody");
    tableBody.innerHTML = "";

    data.forEach(result => {
        const shortFeedback = result.feedback.substring(0, 100);
        const feedback =
            result.feedback.length > 100
                ? `<span class="short-feedback">${formatFeedback(shortFeedback)}... <a href="#" class="see-more">See more</a></span>
                   <span class="full-feedback" style="display:none;">${formatFeedback(result.feedback)} <a href="#" class="see-less">See less</a></span>`
                : formatFeedback(result.feedback);

        const grade = result.grade || calculateGrade(result.marks);

        const row = document.createElement("tr");
        row.innerHTML = `
            <td>${result.student_id}</td>
            <td><a href="${result.code_zip_path}" target="_blank">Download Code</a></td>
            <td>${result.marks}</td>
            <td>${grade}</td>
            <td class="feedback">${feedback}</td>
        `;
        tableBody.appendChild(row);
    });

    attachFeedbackToggle(); // Attach event listeners for feedback expansion
    displayTablePage(1);
}

function formatFeedback(feedback) {
    return feedback
        .replace(/\*\*(.*?)\*\*/g, "<strong>$1</strong>") // Bold **text**
        .replace(/(?:^|\n)([*-])\s*(.*?)(?=\n|$)/g, "<ul><li>$2</li></ul>") // Bullet list
        .replace(/(?:^|\n)(\d+)\.\s*(.*?)(?=\n|$)/g, "<ol><li>$2</li></ol>") // Numbered list
        .replace(/\n/g, "<br>"); // Line breaks
}

// Toggle feedback visibility efficiently using event delegation
function attachFeedbackToggle() {
    document.querySelector("#resultsTable").addEventListener("click", (event) => {
        if (event.target.classList.contains("see-more")) {
            event.preventDefault();
            const shortFeedback = event.target.closest(".short-feedback");
            const fullFeedback = shortFeedback.nextElementSibling;
            shortFeedback.style.display = "none";
            fullFeedback.style.display = "inline";
        } else if (event.target.classList.contains("see-less")) {
            event.preventDefault();
            const fullFeedback = event.target.closest(".full-feedback");
            const shortFeedback = fullFeedback.previousElementSibling;
            fullFeedback.style.display = "none";
            shortFeedback.style.display = "inline";
        }
    });
}

// Grade calculation function
function calculateGrade(marks) {
    return marks >= 90 ? "A+" :
           marks >= 80 ? "A" :
           marks >= 70 ? "B" :
           marks >= 60 ? "C" :
           marks >= 50 ? "D" : "F";
}

// Search function
function searchStudent() {
    const searchInput = document.getElementById("searchInput").value.toLowerCase();
    const rows = document.querySelectorAll("#resultsTable tbody tr");
    let studentFound = false;

    rows.forEach(row => {
        const studentId = row.cells[0].textContent.toLowerCase();
        if (studentId.includes(searchInput)) {
            row.style.display = "";
            studentFound = true;
        } else {
            row.style.display = "none";
        }
    });

    if (!studentFound) alert("Student ID does not exist.");
}

function sortTable(column) {
    const table = document.querySelector("#resultsTable tbody");
    const rows = Array.from(table.querySelectorAll("tr"));
    let columnIndex = column === "marks" ? 2 : 3;

    rows.sort((a, b) => {
        let valA = a.children[columnIndex].innerText.trim();
        let valB = b.children[columnIndex].innerText.trim();
        
        if (column === "marks") {
            return parseFloat(valB) - parseFloat(valA);
        } else {
            return valA.localeCompare(valB);
        }
    });

    table.innerHTML = "";
    rows.forEach(row => table.appendChild(row));
}

function filterTable(status) {
    const table = document.querySelector("#resultsTable tbody");
    const rows = Array.from(table.querySelectorAll("tr"));
    
    rows.forEach(row => {
        let grade = row.children[3].innerText.trim().toLowerCase();
        if ((status === "pass" && grade !== "a" && grade !== "b" && grade !== "c") ||
            (status === "fail" && (grade === "a" || grade === "b" || grade === "c"))) {
            row.style.display = "none";
        } else {
            row.style.display = "table-row";
        }
    });
}
// Pagination logic
let currentPage = 1;
const rowsPerPage = 10;

function displayTablePage(page) {
    const table = document.getElementById("resultsTable").getElementsByTagName("tbody")[0];
    const rows = table.getElementsByTagName("tr");
    const totalPages = Math.ceil(rows.length / rowsPerPage);

    Array.from(rows).forEach((row, index) => {
        row.style.display = index >= (page - 1) * rowsPerPage && index < page * rowsPerPage ? "" : "none";
    });

    document.getElementById("btnPrev").disabled = page === 1;
    document.getElementById("btnNext").disabled = page === totalPages;
    currentPage = page;
}

function prevPage() {
    if (currentPage > 1) {
        displayTablePage(--currentPage);
    }
}

function nextPage() {
    const table = document.getElementById("resultsTable").getElementsByTagName("tbody")[0];
    const totalRows = table.getElementsByTagName("tr").length;
    const totalPages = Math.ceil(totalRows / rowsPerPage);

    if (currentPage < totalPages) {
        displayTablePage(++currentPage);
    }
}

// Initialize pagination on page load
document.addEventListener("DOMContentLoaded", () => {
    displayTablePage(1);
});
