const btns = document.getElementsByTagName("button");
let opr1 = null;
let opr2 = null;
let result = null;
let operator = null;
let displayResult = "";


let oprs = ['+', '-', '*', '/'];


let oprStack = [];
let oprandStack = [];


function display(content, isSetDisplay = false) {
    const display = document.getElementById("displayScreen");
    display.innerText = content;
    if (isSetDisplay) {
        displayResult = String(content);
    }
}


function calc() {
    while (oprStack.length > 0) {
        opr2 = oprandStack.pop();
        opr1 = oprandStack.pop();
        operator = oprStack.pop();
        console.log(`op1:${opr1},op2:${opr2},operator:${operator}`);
        if (operator == '+') {
            result = opr1 + opr2;
            display(String(result), true);
        }
        else if (operator == '-') {
            result = opr1 - opr2;
            display(String(result), true)
        }
        else if (operator == '*') {
            result = opr1 * opr2;
            display(String(result), true)
        }
        else {
            result = opr1 / opr2;
            display(String(result), true)
        }
        oprandStack.unshift(result);
    }
}


Array.from(btns).forEach((btn) => {
    btn.addEventListener('click', () => {
        const txt = btn.textContent;
        if (txt === "=") {
            calc();
            let res = oprandStack[0];
            display(res, true)
        } else if (oprs.includes(txt)) {
            displayResult += txt;
            display(displayResult);
            oprStack.unshift(txt);
            console.log(oprStack)
        } else if (txt === 'X') {
            let newStr = displayResult.slice(0, -1);
            display(newStr, true)
            let firstNum = String(oprandStack[0]);
            if (firstNum.length > 1) {
                firstNum = firstNum.slice(0, -1);
                oprandStack[0] = Number(firstNum);
            } else {
                oprandStack.shift();
            }
        } else {
            displayResult += txt;
            display(displayResult);
            if (oprandStack.length == 0) {
                oprandStack.unshift(Number(txt));
            }
            else if (oprandStack.length > oprStack.length == 1) {
                let prevNum = oprandStack[0];
                let num = String(prevNum) + txt;
                oprandStack[0] = Number(num);
            }
            else {
                oprandStack.unshift(Number(txt));
            }
        }
    })


})
