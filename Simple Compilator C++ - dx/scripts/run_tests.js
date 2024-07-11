const { exec } = require('child_process');

const testFiles = ['tests/test1.src', 'tests/test2.src'];

testFiles.forEach((file, index) => {
    exec(`./simple_compiler ${file}`, (error, stdout, stderr) => {
        if (error) {
            console.error(`Error executing ${file}: ${stderr}`);
            return;
        }

        console.log(`Test ${index + 1} (${file}):\n${stdout}`);
    });
});
