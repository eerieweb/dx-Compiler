function compileCode() {
    const sourceCode = document.getElementById('sourceCode').value;
    const outputElement = document.getElementById('output');
    const logsElement = document.getElementById('logs');

    fetch('/compile', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ sourceCode })
    })
    .then(response => response.json())
    .then(data => {
        outputElement.textContent = data.output;
        logsElement.textContent = data.logs;
    })
    .catch(error => {
        console.error('Error:', error);
        outputElement.textContent = 'Error occurred while compiling.';
        logsElement.textContent = '';
    });
}

function toggleTheme() {
    document.body.classList.toggle('night-mode');
    const isNightMode = document.body.classList.contains('night-mode');
    localStorage.setItem('nightMode', isNightMode);
}

// On page load, apply the saved theme
document.addEventListener('DOMContentLoaded', (event) => {
    const nightMode = localStorage.getItem('nightMode') === 'true';
    if (nightMode) {
        document.body.classList.add('night-mode');
        document.getElementById('theme-toggle').checked = true;
    }
});
