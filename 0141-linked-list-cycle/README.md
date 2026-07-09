# 0141 - Linked List Cycle

## Problem
Given the head of a linked list, determine whether the linked list has a cycle.

A cycle exists if a node can be reached again by continuously following the next pointer.

## Key Insight
If one pointer moves one step at a time and another moves two steps at a time, they will meet if and only if a cycle exists.

This is Floyd's cycle detection algorithm.

## Approach
Use two pointers, `slow` and `fast`.

- Move `slow` one step at a time.
- Move `fast` two steps at a time.
- If the list has a cycle, the two pointers will eventually point to the same node.
- If `fast` reaches the end, the list has no cycle.

## Why It Works
Inside a cycle, the faster pointer gains one node on the slower pointer each step.

Since the cycle has finite length, that gap must eventually become zero, which means the pointers meet.

If there is no cycle, the faster pointer hits `null` first, so a meeting never occurs.

## Complexity
- Time: `O(n)`
- Space: `O(1)`

## Python
```python
class Solution:
    def hasCycle(self, head):
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return True

        return False
```

## Java
```java
class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
}
```

## C++
```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
```