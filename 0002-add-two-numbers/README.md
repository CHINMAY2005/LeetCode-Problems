# 0002 - Add Two Numbers

## Problem
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

## Key Insight
Since the digits are stored in reverse order, the head of the list represents the least significant digit. We can traverse both lists simultaneously, adding the values from corresponding nodes along with any carry-over from the previous addition.

## Approach
1. Initialize a `dummy` node to construct the result list and a `carry` variable set to 0.
2. Traverse both linked lists until both are fully traversed and the `carry` is 0:
   - Extract the node values (use 0 if a list has already ended).
   - Compute the sum: `total = val1 + val2 + carry`.
   - Update the carry: `carry = total / 10`.
   - Create a new node with value `total % 10` and append it to our result list.
   - Advance the pointers for `l1`, `l2`, and the result list.
3. Return `dummy.next`.

## Why It Works
This mimics the standard column-addition algorithm from right to left. The reverse order of digits in the linked lists aligns perfectly with this processing direction, allowing us to build the resulting list in one pass.

## Complexity
- Time: `O(max(m, n))` where `m` and `n` are the lengths of `l1` and `l2` respectively.
- Space: `O(max(m, n))` to store the resulting linked list.

## Python
```python
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):
        dummy = ListNode(0)
        curr = dummy
        carry = 0
        
        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            total = val1 + val2 + carry
            carry = total // 10
            curr.next = ListNode(total % 10)
            
            curr = curr.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            
        return dummy.next
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        int carry = 0;
        
        while (l1 != null || l2 != null || carry != 0) {
            int val1 = (l1 != null) ? l1.val : 0;
            int val2 = (l2 != null) ? l2.val : 0;
            
            int total = val1 + val2 + carry;
            carry = total / 10;
            curr.next = new ListNode(total % 10);
            
            curr = curr.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        
        return dummy.next;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            int total = val1 + val2 + carry;
            carry = total / 10;
            curr->next = new ListNode(total % 10);
            
            curr = curr->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        return dummy.next;
    }
};
```
