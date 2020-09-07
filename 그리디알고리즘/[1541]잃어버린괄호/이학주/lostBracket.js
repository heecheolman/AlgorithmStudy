const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


rl.on('line', function(line) {
    let input = line.split('-');

    for (let i = 0; i < input.length; i++) {
        if (input[i].indexOf('+') != -1) {
            let temp = input[i].split('+');
            let hap = 0;
            for (let j = 0; j < temp.length; j++) {
                hap = Number(hap) + Number(temp[j]);
            }
            input[i] = hap;
        }
    }

    let result = input[0];
    for (let i = 1; i < input.length; i++) {
        result = Number(result) - Number(input[i]);
    }

    console.log(result);
    rl.close();
}).on("close", function() {
    process.exit();
});
