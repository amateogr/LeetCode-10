function connect(root: Node | null): Node | null {
    let leftmost = root;
    while (leftmost && leftmost.left) {
        let head = leftmost;
        while (head) {
            head.left.next = head.right;
            if (head.next) {
                head.right.next = head.next.left;
            }
            head = head.next;
        }
        leftmost = leftmost.left;
    }
    return root;
}