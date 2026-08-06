class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }
        
        ListNode current = head;
        int len = 1;
        while (current.next != null) {
            current = current.next;
            len++;
        }
        
        current.next = head;
        k = k % len;
        int stepsToNewHead = len - k;
        
        ListNode newTail = current;
        for (int i = 0; i < stepsToNewHead; i++) {
            newTail = newTail.next;
        }
        
        ListNode newHead = newTail.next;
        newTail.next = null;
        
        return newHead;
    }
}