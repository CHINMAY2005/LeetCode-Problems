# 0025 - Reverse Nodes in k-Group

## Problem
Given the head of a linked list, reverse the nodes of the list `k` at a time, and return the modified list.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

## Key Insight
An iterative approach using a dummy node avoids the stack frames of a recursive solution. We locate the $k$-th node in the current segment. If it exists, we reverse that segment in-place and connect it back. If it does not exist (meaning there are fewer than $k$ nodes left), we leave the remaining nodes unchanged.

## Approach
1. Create a sentinel `dummy` node and point `dummy.next = head`.
2. Initialize `groupPrev = dummy`.
3. In a loop, attempt to find the $k$-th node relative to `groupPrev`:
   - Start a pointer `kth = groupPrev`.
   - Traverse forward $k$ times. If `kth` becomes `null` at any step, break the main loop (since fewer than $k$ nodes remain).
4. Save the node immediately following the $k$-th node: `groupNext = kth.next`.
5. Reverse the sub-list of size $k$ starting at `groupPrev.next` and ending before `groupNext`:
   - Set the initial `prev` node of our reversal loop to `groupNext` (so the tail of the reversed sub-list points to the remainder of the list).
   - Standard linked list reversal: Update `.next` pointers until `curr` reaches `groupNext`.
6. Reconnect the reversed group back to the main list:
   - Save the current head of the sub-list (which will become the tail of the reversed sub-list): `temp = groupPrev.next`.
   - Connect the prefix: `groupPrev.next = kth`.
   - Move `groupPrev` to the tail of the reversed sub-list: `groupPrev = temp`.
7. Return `dummy.next`.

## Why It Works
By reversing the sub-list with `prev` initialized to `groupNext`, the reversed segment automatically links its new tail to the rest of the list. Reconnecting `groupPrev.next = kth` updates the parent group to point to the new head of the reversed segment.

## Complexity
- Time: `O(n)` where `n` is the number of nodes in the linked list, as we process each node at most twice.
- Space: `O(1)` auxiliary space, as all nodes are reversed in place.

## Python
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head, k):
        dummy = ListNode(-1)
        dummy.next = head
        groupPrev = dummy
        
        while True:
            kth = groupPrev
            for _ in range(k):
                kth = kth.next
                if not kth:
                    break
            if not kth:
                break
                
            groupNext = kth.next
            
            # Reverse group
            prev = groupNext
            curr = groupPrev.next
            while curr != groupNext:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
                
            # Connect group
            temp = groupPrev.next
            groupPrev.next = kth
            groupPrev = temp
            
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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode groupPrev = dummy;
        
        while (true) {
            ListNode kth = groupPrev;
            for (int i = 0; i < k; i++) {
                kth = kth.next;
                if (kth == null) {
                    break;
                }
            }
            if (kth == null) {
                break;
            }
            
            ListNode groupNext = kth.next;
            
            // Reverse group
            ListNode prev = groupNext;
            ListNode curr = groupPrev.next;
            while (curr != groupNext) {
                ListNode temp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = temp;
            }
            
            // Connect group
            ListNode temp = groupPrev.next;
            groupPrev.next = kth;
            groupPrev = temp;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* groupPrev = &dummy;
        
        while (true) {
            ListNode* kth = groupPrev;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (kth == nullptr) {
                    break;
                }
            }
            if (kth == nullptr) {
                break;
            }
            
            ListNode* groupNext = kth->next;
            
            // Reverse group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            
            // Connect group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        
        return dummy.next;
    }
};
```
