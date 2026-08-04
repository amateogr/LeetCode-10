struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* cursor = head;
    for (int i = 0; i < k; i++) {
        if (cursor == NULL) {
            return head;
        }
        cursor = cursor->next;
    }
    
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    
    for (int i = 0; i < k; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    head->next = reverseKGroup(curr, k);
    
    return prev;
}