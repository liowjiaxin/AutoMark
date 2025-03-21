// let currentPage = 1;
// const rowsPerPage = 10;

// function displayTablePage(page) {
//   const table = document.getElementById("resultsTable").getElementsByTagName('tbody')[0];
//   const rows = table.getElementsByTagName('tr');
//   const totalRows = rows.length;
//   const totalPages = Math.ceil(totalRows / rowsPerPage);

//   for (let i = 0; i < totalRows; i++) {
//     rows[i].style.display = (i >= (page - 1) * rowsPerPage && i < page * rowsPerPage) ? '' : 'none';
//   }

//   document.getElementById("btnPrev").disabled = page === 1;
//   document.getElementById("btnNext").disabled = page === totalPages;
// }

// function prevPage() {
//   if (currentPage > 1) {
//     currentPage--;
//     displayTablePage(currentPage);
//   }
// }

// function nextPage() {
//   const table = document.getElementById("resultsTable").getElementsByTagName('tbody')[0];
//   const rows = table.getElementsByTagName('tr');
//   const totalRows = rows.length;
//   const totalPages = Math.ceil(totalRows / rowsPerPage);

//   if (currentPage < totalPages) {
//     currentPage++;
//     displayTablePage(currentPage);
//   }
// }

// document.addEventListener('DOMContentLoaded', () => {
//   const table = document.getElementById("resultsTable").getElementsByTagName('tbody')[0];
//   const rows = table.getElementsByTagName('tr');
//   for (let i = 0; i < rows.length; i++) {
//     rows[i].style.display = 'none';
//   }
//   displayTablePage(currentPage);
// });
