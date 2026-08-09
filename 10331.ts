function isValidSerialization(preorder: string): boolean {
    let slots = 1;
    const n = preorder.length;
    let i = 0;
    while (i < n) {
        if (slots <= 0) return false;
        if (preorder.charCodeAt(i) === 35) {
            slots--;
            i += 2;
        } else {
            while (i < n && preorder.charCodeAt(i) !== 44) {
                i++;
            }
            slots++;
            i++;
        }
    }
    return slots === 0;
}