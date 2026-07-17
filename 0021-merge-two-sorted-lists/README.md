# 0021 - Merge Two Sorted Lists

## Problem
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

## Key Insight
Using an iterative approach with a sentinel (dummy) node allows us to easily handle edge cases, such as when one list is initially empty. We track the tail of our merged list and append nodes sequentially.

## Approach
1. Create a dummy node representing the head of our merged list.
2. Maintain a `tail` pointer (initially pointing to the dummy node).
3. While both `list1` and `list2` are not null:
   - Compare the values of the nodes at `list1` and `list2`.
   - Append the smaller node to `tail.next`.
   - Move the pointer of the smaller node (`list1` or `list2`) to its next node.
   - Advance the `tail` pointer.
4. After the loop, at least one of the lists is empty. Append the remaining non-empty list directly to `tail.next`.
5. Return `dummy.next` as the head of the merged list.

## Why It Works
Since both input lists are already sorted, the smallest overall node is always at the head of either `list1` or `list2`. Splicing nodes in place avoids copying nodes and achieves optimal space efficiency.

## Complexity
- Time: `O(n + m)` where `n` and `m` are the lengths of the two linked lists.
- Space: `O(1)` as we splice the nodes in place without using additional memory.

## Python
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1, list2):
        dummy = ListNode(-1)
        tail = dummy
        
        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
            
        tail.next = list1 if list1 else list2
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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }
        
        tail.next = (list1 != null) ? list1 : list2;
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        tail->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;
    }
};
```
