# 0206 - Reverse Linked List

## Problem
Given the head of a singly linked list, reverse the list, and return the reversed list.

## Key Insight
The list can be reversed by flipping each node's next pointer one at a time while walking through the list.

That means we only need a few pointers to track the previous, current, and next nodes.

## Approach
Iterate through the list and reverse the links as you go.

- Keep a pointer to the previous node.
- Save the next node before changing the current node's pointer.
- Point the current node back to the previous node.
- Advance both pointers forward.

When the traversal ends, the previous pointer is the new head.

## Why It Works
At each step, the part of the list before the current node is already reversed, and the remaining part is still in its original order.

By redirecting one pointer at a time, the algorithm preserves access to the rest of the list and eventually reverses every link exactly once.

## Complexity
- Time: `O(n)`
- Space: `O(1)`

## Python
```python
class Solution:
    def reverseList(self, head):
        prev = None
        current = head

        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        return prev
```

## Java
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;

        while (current != null) {
            ListNode nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }
}
```

## C++
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }
};
```