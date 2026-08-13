const isValid = (code) => {
    const stack = [];
    let i = 0;
    const n = code.length;
    while (i < n) {
        if (code[i] === '<') {
            if (i + 9 < n && code.startsWith('<![CDATA[', i)) {
                if (stack.length === 0) return false;
                const endCdata = code.indexOf(']]>', i + 9);
                if (endCdata === -1) return false;
                i = endCdata + 3;
            } else if (code[i + 1] === '/') {
                const endTag = code.indexOf('>', i + 2);
                if (endTag === -1) return false;
                const tagName = code.slice(i + 2, endTag);
                if (stack.length === 0 || stack.pop() !== tagName) return false;
                i = endTag + 1;
                if (stack.length === 0 && i < n) return false;
            } else {
                const endTag = code.indexOf('>', i + 1);
                if (endTag === -1) return false;
                const tagName = code.slice(i + 1, endTag);
                if (tagName.length < 1 || tagName.length > 9) return false;
                for (let k = 0; k < tagName.length; k++) {
                    const charCode = tagName.charCodeAt(k);
                    if (charCode < 65 || charCode > 90) return false;
                }
                stack.push(tagName);
                i = endTag + 1;
            }
        } else {
            if (stack.length === 0) return false;
            i++;
        }
    }
    return stack.length === 0;
};