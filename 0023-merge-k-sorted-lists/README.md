# 0023 - Merge k Sorted Lists

## Problem
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

## Key Insight
Instead of merging lists one by one sequentially (which would take $O(k \cdot N)$ time), we can merge them pairwise using a divide-and-conquer strategy. This reduces the number of merge stages to $\log_2 k$, leading to a much faster $O(N \log k)$ runtime and $O(1)$ auxiliary space.

## Approach
1. If the input list `lists` is empty, return `null`.
2. Maintain an `interval` variable, starting at `1`.
3. While `interval` is less than the total number of lists `n`:
   - Iterate through the lists from `0` to `n - interval`, in steps of `interval * 2`.
   - Merge the list at index `i` with the list at index `i + interval` using the standard `mergeTwoLists` helper. Store the merged list back at index `i`.
   - Double the `interval` (`interval *= 2`).
4. Finally, all lists will be merged into `lists[0]`. Return `lists[0]`.

## Why It Works
Pairwise merging processes list merges in parallel levels. Since the number of remaining lists is halved in each iteration, the merge process resembles a binary merge tree of height $\log k$, ensuring balanced work at each step.

## Complexity
- Time: `O(N log k)` where `N` is the total number of nodes across all lists, and `k` is the number of linked lists.
- Space: `O(1)` as we merge the lists in place iteratively without recursion stacks.

## Python
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeKLists(self, lists):
        if not lists:
            return None
            
        n = len(lists)
        interval = 1
        
        while interval < n:
            for i in range(0, n - interval, interval * 2):
                lists[i] = self.mergeTwoLists(lists[i], lists[i + interval])
            interval *= 2
            
        return lists[0]
        
    def mergeTwoLists(self, l1, l2):
        dummy = ListNode(-1)
        tail = dummy
        
        while l1 and l2:
            if l1.val <= l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
            
        tail.next = l1 if l1 else l2
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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        
        int n = lists.length;
        int interval = 1;
        
        while (interval < n) {
            for (int i = 0; i < n - interval; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
    
    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
        
        tail.next = (l1 != null) ? l1 : l2;
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

#include <vector>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        int n = lists.size();
        int interval = 1;
        
        while (interval < n) {
            for (int i = 0; i < n - interval; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};
```
