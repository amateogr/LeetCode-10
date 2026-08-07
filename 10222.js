function countNodes(root) {
    if (!root) return 0;
    let leftHeight = 0, rightHeight = 0;
    let curr = root;
    while (curr) {
        leftHeight++;
        curr = curr.left;
    }
    curr = root;
    while (curr) {
        rightHeight++;
        curr = curr.right;
    }
    if (leftHeight === rightHeight) {
        return (1 << leftHeight) - 1;
    }
    return 1 + countNodes(root.left) + countNodes(root.right);
}