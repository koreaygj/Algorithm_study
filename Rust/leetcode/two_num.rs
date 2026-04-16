impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy_head = Box::new(ListNode.new(0));
        let mut current = &mut dummy_head;
        let mut carry = 0;

        let(mut p1, mut p2) = l1, l2;

        while p1.is_some() || p2.is_some() || carry != 0 {
          let mut sum = carry;
          if let Some(node) = p1 {
            sum += node.val;
            p1 = node.next;
          }
          if let Some(node) = p2 {
            sum += node.val;
            p2 = node.next;
          }

          carry = sum / 10;
          current.next = current.next.as_mut().unwrap();
        }

        dummy_head.next
    }
}
