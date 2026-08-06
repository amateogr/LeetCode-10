struct ListNode* split(struct ListNode* head, int n) {
    for (int i = 1; head && i < n; i++) {
        head = head->next;
    }
    if (!head) return 0;
    struct ListNode* second = head->next;
    head->next = 0;
    return second;
}

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2, struct ListNode** tail) {
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    while (curr->next) {
        curr = curr->next;
    }
    *tail = curr;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    int len = 0;
    struct ListNode* curr = head;
    while (curr) {
        len++;
        curr = curr->next;
    }
    struct ListNode dummy;
    dummy.next = head;
    for (int step = 1; step < len; step *= 2) {
        struct ListNode* prev = &dummy;
        curr = dummy.next;
        while (curr) {
            struct ListNode* left = curr;
            struct ListNode* right = split(left, step);
            curr = split(right, step);
            struct ListNode* tail = 0;
            struct ListNode* merged = merge(left, right, &tail);
            prev->next = merged;
            prev = tail;
        }
    }
    return dummy.next;
}