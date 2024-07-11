const { exec } = require('child_process');
const fs = require('fs');

const testFiles = ['tests/test1.src', 'tests/test2.src'];

let report = 'Performance Report\n\n';

testFiles.forEach((file, index) => {
    const startTime = process.hrtime();
    
    exec(`./simple_compiler ${file}`, (error, stdout, stderr) => {
        if (error) {
            console.error(`Error executing ${file}: ${stderr}`);
            return;
        }

        const endTime = process.hrtime(startTime);
        const executionTime = endTime[0] * 1000 + endTime[1] / 1000000; // convert to milliseconds

        report += `Test ${index + 1} (${file}):\n`;
        report += `Output:\n${stdout}\n`;
        report += `Execution Time: ${executionTime.toFixed(3)} ms\n\n`;

        if (index === testFiles.length - 1) {
            fs.writeFileSync('performance_report.txt', report);
            console.log('Performance report generated as performance_report.txt');
        }
    });
});
