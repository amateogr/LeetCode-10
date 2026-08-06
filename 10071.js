const simplifyPath = path => {
    const stack = [];
    for (const part of path.split('/')) {
        if (part === '..') stack.pop();
        else if (part && part !== '.') stack.push(part);
    }
    return `/${stack.join('/')}`;
};