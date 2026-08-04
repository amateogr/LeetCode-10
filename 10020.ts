function isValid(s: string): boolean {
    const stack: string[] = [];
    const map: { [key: string]: string } = {
        ')': '(',
        '}': '{',
        ']': '['
    };

    for (const char of s) {
        if (char in map) {
            const topElement = stack.length === 0 ? '#' : stack.pop();
            if (topElement !== map[char]) {
                return false;
            }
        } else {
            stack.push(char);
        }
    }

    return stack.length === 0;
}