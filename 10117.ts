function connect(root: Node | null): Node | null {
    let curr = root;
    let head: Node | null = null;
    let tail: Node | null = null;

    while (curr) {
        while (curr) {
            if (curr.left) {
                if (tail) {
                    tail.next = curr.left;
                } else {
                    head = curr.left;
                }
                tail = curr.left;
            }
            if (curr.right) {
                if (tail) {
                    tail.next = curr.right;
                } else {
                    head = curr.right;
                }
                tail = curr.right;
            }
            curr = curr.next;
        }
        curr = head;
        head = null;
        tail = null;
    }

    return root;
}