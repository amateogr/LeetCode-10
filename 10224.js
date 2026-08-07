const calculate = (s) => {
    let stack = [];
    let result = 0;
    let number = 0;
    let sign = 1;
    for (let i = 0; i < s.length; i++) {
        const c = s.charCodeAt(i);
        if (c >= 48 && c <= 57) {
            number = number * 10 + (c - 48);
        } else if (c === 43) {
            result += sign * number;
            sign = 1;
            number = 0;
        } else if (c === 45) {
            result += sign * number;
            sign = -1;
            number = 0;
        } else if (c === 40) {
            stack.push(result);
            stack.push(sign);
            result = 0;
            sign = 1;
        } else if (c === 41) {
            result += sign * number;
            result *= stack.pop();
            result += stack.pop();
            number = 0;
        }
    }
    return result + sign * number;
};