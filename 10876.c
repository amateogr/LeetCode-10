struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *s = head, *f = head;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
    }
    return s;
}