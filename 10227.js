function calculate(s) {
    let result = 0, lastNumber = 0, currentNumber = 0, lastOperator = '+';
    const n = s.length;
    for (let i = 0; i < n; i++) {
        let char = s[i];
        if (char >= '0' && char <= '9') {
            currentNumber = currentNumber * 10 + (char.charCodeAt(0) - 48);
        }
        if ((char < '0' && char !== ' ') || i === n - 1) {
            if (lastOperator === '+' || lastOperator === '-') {
                result += lastNumber;
                lastNumber = lastOperator === '+' ? currentNumber : -currentNumber;
            } else if (lastOperator === '*') {
                lastNumber = Math.trunc(lastNumber * currentNumber);
            } else if (lastOperator === '/') {
                lastNumber = Math.trunc(lastNumber / currentNumber);
            }
            lastOperator = char;
            currentNumber = 0;
        }
    }
    result += lastNumber;
    return result;
}