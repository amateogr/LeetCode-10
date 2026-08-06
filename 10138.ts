function copyRandomList(head: Node | null): Node | null {
    if (!head) return null;

    let curr: Node | null = head;
    while (curr) {
        curr.next = new Node(curr.val, curr.next, null);
        curr = curr.next.next;
    }

    curr = head;
    while (curr) {
        if (curr.random) {
            curr.next.random = curr.random.next;
        }
        curr = curr.next.next;
    }

    curr = head;
    let pseudoHead = new Node(0);
    let copyCurr = pseudoHead;

    while (curr) {
        let next = curr.next.next;
        copyCurr.next = curr.next;
        curr.next = next;
        copyCurr = copyCurr.next;
        curr = next;
    }

    return pseudoHead.next;
}