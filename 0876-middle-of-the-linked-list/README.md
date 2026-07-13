# 0876 - Middle of the Linked List

## Problem
Given the `head` of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

## Key Insight
We can use a two-pointer approach (slow and fast). The slow pointer moves one step at a time, while the fast pointer moves two steps. When the fast pointer reaches the end of the list, the slow pointer will be exactly at the middle.

## Approach
1. Initialize two pointers, `slow` and `fast`, to the `head` of the linked list.
2. Traverse the list in a loop:
   - Move `slow` forward by one node: `slow = slow.next`.
   - Move `fast` forward by two nodes: `fast = fast.next.next`.
   - Continue until `fast` is null or `fast.next` is null.
3. Return `slow`.

## Why It Works
Since the fast pointer travels twice as fast as the slow pointer, it will cover twice the distance. By the time `fast` reaches the end of the list (distance $N$), `slow` will have covered distance $N/2$, which corresponds to the middle element.

## Complexity
- Time: `O(n)` where `n` is the number of nodes in the linked list.
- Space: `O(1)` as we only use two pointers.

## Python
```python
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def middleNode(self, head):
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
```

## Java
```java
/**
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
```

## C++
```cpp
/**
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```
