struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *lastSorted = head;
    struct ListNode *curr = head->next;
    while (curr) {
        if (lastSorted->val <= curr->val) {
            lastSorted = lastSorted->next;
        } else {
            struct ListNode *prev = &dummy;
            while (prev->next->val <= curr->val) {
                prev = prev->next;
            }
            lastSorted->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = lastSorted->next;
    }
    return dummy.next;
}