# 0024 - Swap Nodes in Pairs

## Problem
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

## Key Insight
Using an iterative approach with a dummy node simplifies the pointer reassignment. By tracking a `prev` node that points to the pair currently being swapped, we can seamlessly wire up the swaps in-place without losing references.

## Approach
1. Create a sentinel dummy node: `dummy` node with value `-1`.
2. Connect `dummy.next` to `head`.
3. Set a pointer `prev = dummy`.
4. While `prev.next` and `prev.next.next` are not null:
   - Identify the two adjacent nodes to swap: `first = prev.next`, `second = prev.next.next`.
   - Update pointers to perform the swap:
     - Connect the first node to the rest of the list: `first.next = second.next`.
     - Reverse the pair direction: `second.next = first`.
     - Connect the previous part of the list to the new first element: `prev.next = second`.
   - Move the `prev` pointer past the swapped pair: `prev = first`.
5. Return `dummy.next` as the head of the modified list.

## Why It Works
By caching references to `first` and `second`, we can cleanly restructure the linkages. Moving `prev` to `first` correctly positions our cursor for the next pair, as `first` has now become the second element in the pair after swapping.

## Complexity
- Time: `O(n)` where `n` is the number of nodes in the linked list, as we visit each node exactly once.
- Space: `O(1)` as we only rearrange node links in place.

## Python
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapPairs(self, head):
        dummy = ListNode(-1)
        dummy.next = head
        prev = dummy
        
        while prev.next and prev.next.next:
            first = prev.next
            second = prev.next.next
            
            # Swap
            first.next = second.next
            second.next = first
            prev.next = second
            
            # Re-position prev
            prev = first
            
        return dummy.next
```

## Java
```java
// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy;
        
        while (prev.next != null && prev.next.next != null) {
            ListNode first = prev.next;
            ListNode second = prev.next.next;
            
            // Swap
            first.next = second.next;
            second.next = first;
            prev.next = second;
            
            // Re-position prev
            prev = first;
        }
        
        return dummy.next;
    }
}
```

## C++
```cpp
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Swap
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Re-position prev
            prev = first;
        }
        
        return dummy.next;
    }
};
```
