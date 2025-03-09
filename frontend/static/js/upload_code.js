document.addEventListener('DOMContentLoaded', () => {
  document.getElementById("submit-assignment").addEventListener("click", submitAssignment);
  document.getElementById("stop-run-code").addEventListener("click", stopRunCode);
  document.getElementById("run-code").addEventListener("click", runCode);

  // Initialize Monaco Editor
  require.config({ paths: { 'vs': 'https://cdnjs.cloudflare.com/ajax/libs/monaco-editor/0.47.0/min/vs' }});
  require(['vs/editor/editor.main'], function() {
    window.editor = monaco.editor.create(document.getElementById('monaco-editor'), {
      value: '#!/bin/bash\n# Type your commands here\n# Example: python main.py',
      language: 'shell',
      theme: 'vs',
      minimap: { enabled: false },
      lineNumbers: 'on',
      roundedSelection: false,
      scrollBeyondLastLine: false,
      readOnly: false,
      fontSize: 14,
      automaticLayout: true,
      wordWrap: 'on',
      wrappingStrategy: 'advanced'
    });
  });
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
  const submitBtn = document.getElementById("submit-assignment");
  const runBtn = document.getElementById("run-code");
  const progressBar = document.getElementById("progress-bar");

  // Set loading state
  setButtonLoading(submitBtn, true);
  runBtn.disabled = true;

  // Show progress bar
  progressBar.style.display = "block";
  let progress = 0;

  const interval = setInterval(() => {
    if (progress >= 100) {
      clearInterval(interval);
      progressBar.style.display = "none"; // Hide progress bar
      setButtonLoading(submitBtn, false);
      runBtn.disabled = false; // Re-enable button
    } else {
      progress += 10;
      progressBar.value = progress;
    }
  }, 500); // Increased delay to 500ms

  const studentId = document.getElementById("student-id").value;
  const language = document.getElementById("language").value;
  const version = document.getElementById("version").value;
  const studentAnswerZipFilename = document.getElementById("student-answer-zip-filename").value;
  const markingSchemeFilename = document.getElementById("marking-scheme-filename").value;

  if (!language || language === '-') {
    alert("Please select a language.");
    resetProgressBar();
    return;
  }

  if (!version || version === '-') {
    alert("Please select a version.");
    resetProgressBar();
    return;
  }

  if (!markingSchemeFilename) {
    alert("Please upload the marking scheme.");
    resetProgressBar();
    return;
  }

  if (!studentAnswerZipFilename) {
    alert("Please upload the student's answer.");
    resetProgressBar();
    return;
  }

  if (!studentId) {
    alert("Please enter the student ID.");
    resetProgressBar();
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
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(data)
  })
    .then(response => response.json())
    .then(data => {
      console.log("Received Data:", data); // Debugging: Ensure data is received correctly

      // Get the result card elements
      const marksElement = document.getElementById("marks");
      const gradeElement = document.getElementById("grade");
      const feedbackElement = document.getElementById("feedback");

      if (marksElement && feedbackElement && gradeElement) {
        marksElement.innerText = data.marks;
        gradeElement.innerText = data.grade || calculateGrade(data.marks);
        feedbackElement.innerHTML = formatFeedback(data.feedback);
      } else {
        console.error("Error: Result card elements not found!");
        alert("Error displaying the results. Please check the result card elements.");
      }

      alert("Assignment submitted successfully!");
    })
    .catch(error => {
      console.error("Error:", error);
      alert("An error occurred while submitting the assignment. Please try again.");
      resetProgressBar();
    });

  function resetProgressBar() {
    clearInterval(interval);
    progressBar.style.display = "none"; // Hide progress bar
    setButtonLoading(submitBtn, false);
    runBtn.disabled = false; // Re-enable button
  }
}

function stopRunCode() {
  // Logic to stop the running code
  alert("Run code stopped.");
}

function setButtonLoading(button, isLoading) {
  if (isLoading) {
    // Store the original text as a data attribute
    button.dataset.originalText = button.textContent;
    button.classList.add('loading');
    button.textContent = '';
  } else {
    button.classList.remove('loading');
    // Restore the original text from the data attribute
    button.textContent = button.dataset.originalText || button.textContent;
  }
  button.disabled = isLoading;
}

function runCode() {
  const runButton = document.getElementById("run-code");
  const submitButton = document.getElementById("submit-assignment");
  
  // Validate inputs
  const language = document.getElementById("language").value;
  const version = document.getElementById("version").value;
  const studentAnswerZipFilename = document.getElementById("student-answer-zip-filename").value;
  const commands = window.editor.getValue()
      .split('\n')
      .filter(line => line.trim() && !line.startsWith('#') && line !== '#!/bin/bash');
  console.log(commands)
  
  if (!language || language === '-') {
    alert("Please select a language.");
    return;
  }

  if (!version || version === '-') {
    alert("Please select a version.");
    return;
  }

  if (!studentAnswerZipFilename) {
    alert("Please upload the student's answer.");
    return;
  }

  if (commands.length === 0) {
    alert("Please enter at least one command to run.");
    return;
  }

  // Set loading state
  setButtonLoading(runButton, true);
  submitButton.disabled = true;

  // Create WebSocket connection
  const ws = new WebSocket(`ws://${window.location.host}/ws/run-code`);

  ws.onopen = () => {
    console.log('WebSocket connection established');
    const data = {
      language,
      version,
      code_zip_filename: studentAnswerZipFilename,
      commands: commands
    };
    ws.send(JSON.stringify(data));
  };

  ws.onmessage = (event) => {
    const logsContent = document.getElementById('logs-content');
    logsContent.innerHTML += event.data + '<br>';
    logsContent.scrollTop = logsContent.scrollHeight;
  };

  ws.onclose = () => {
    console.log('WebSocket connection closed');
    // Reset button states
    setButtonLoading(runButton, false);
    submitButton.disabled = false;
  };

  ws.onerror = (error) => {
    console.error('WebSocket error:', error);
    alert('An error occurred while running the code. Please try again.');
    // Reset button states
    setButtonLoading(runButton, false);
    submitButton.disabled = false;
  };
}

// Function to determine grade if not provided
function calculateGrade(marks) {
  if (marks >= 90) return "A+";
  if (marks >= 80) return "A";
  if (marks >= 70) return "B";
  if (marks >= 60) return "C";
  if (marks >= 50) return "D";
  return "F";
}

// Function to format feedback
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
