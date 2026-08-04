impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode { val: 0, next: head }));
        let mut len = 0;
        {
            let mut curr = dummy.as_ref();
            while let Some(node) = curr {
                curr = node.next.as_ref();
                len += 1;
            }
            len -= 1;
        }
        let target = len - n;
        let mut curr = dummy.as_mut();
        for _ in 0..target {
            if let Some(node) = curr {
                curr = node.next.as_mut();
            }
        }
        if let Some(node) = curr {
            if let Some(next) = node.next.take() {
                node.next = next.next;
            }
        }
        dummy.unwrap().next
    }
}
