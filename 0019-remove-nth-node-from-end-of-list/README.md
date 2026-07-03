# 0019 - Remove Nth Node From End of List

## Problem
Given the head of a linked list, remove the `n`th node from the end of the list and return its head.

## Key Insight
The node to remove can be found with two pointers separated by `n` steps.

Once the fast pointer reaches the end, the slow pointer will be just before the node that must be removed.

## Approach
Use a dummy node before the head to simplify removal near the front.

- Move the fast pointer `n` steps ahead.
- Move both pointers forward together until `fast.next` is `None`.
- Skip the target node by relinking `slow.next`.

The dummy node ensures the head can be removed with the same logic as any other node.

## Why It Works
After the fast pointer advances `n` nodes, the gap between fast and slow is fixed at `n` nodes.

When fast reaches the end, slow is exactly one node before the node that is `n` from the end, so relinking `slow.next` removes the correct element.

## Complexity
- Time: `O(n)`
- Space: `O(1)`

## Python
```python
class Solution:
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0, head)
        fast = dummy
        slow = dummy

        for _ in range(n):
            fast = fast.next

        while fast.next:
            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next
        return dummy.next
```

## Java
```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy;
        ListNode slow = dummy;

        for (int i = 0; i < n; i++) {
            fast = fast.next;
        }

        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;
        return dummy.next;
    }
}
```

## C++
```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy.next;
    }
};
```