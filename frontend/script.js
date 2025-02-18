document.getElementById("submit-assignment").addEventListener("click", () => {
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
});

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
