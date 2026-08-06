class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        l1 = l = ListNode(0)
        l2 = g = ListNode(0)
        while head:
            if head.val < x:
                l.next = head
                l = l.next
            else:
                g.next = head
                g = g.next
            head = head.next
        g.next = None
        l.next = l2.next
        return l1.next   