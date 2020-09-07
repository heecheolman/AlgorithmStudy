const readline = require('readline');
const { isUndefined } = require('util');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

let input = [];
rl.on('line', function (line) {
    input.push(line);
}).on('close', function() {
    let N = input.shift();
    let time = [];
    input.map(function (line) { 
        time.push(line.split(' '));
    })

    //로직
    //endTime이 제일 작은걸 선택
    //endTime보다 작은 startTime 삭제
    //count++ 후 endTime의 length가 0이 될때까지 반복

    let endTime = [];
    let startTime = [];
    time.map(function (input) {
        startTime.push(input.shift());
        endTime.push(input.shift());
    });

    let count = 0;
    
    while (endTime.length != 0) {
        let min = endTime[0];
        for (let i = 0; i < endTime.length; i++) {
            if (Number(min) > Number(endTime[i])) {
                Number(min) = Number(endTime[i]);
            }
        }
        console.log(min);
        
        startTime.forEach(function (element) {
            if (min > element) {
                let search = startTime.indexOf(element);
                if (search != -1) {
                    startTime.splice(search, 1);
                    endTime.splice(search, 1);
                }
            }
        });

        /*
        for (let i = 0; i < startTime.length; i++) {
            if (min > startTime[i]) {
                //여기
                let search = startTime.indexOf(startTime[i]);
                if (search != -1) {
                    startTime.splice(search, 1);
                    endTime.splice(search, 1);
                }
            }
        }
        */
        
        console.log(startTime);
        console.log(endTime);
        count++;
    }

    console.log(count);
});