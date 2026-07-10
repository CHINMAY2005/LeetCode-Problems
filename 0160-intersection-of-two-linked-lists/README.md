# 0160 - Intersection of Two Linked Lists

## Problem
Given the heads of two singly linked lists, return the node at which the two lists intersect.

If the two linked lists have no intersection, return `null`.

## Key Insight
If two lists intersect, then after aligning their tails, both pointers will reach the same node at the same time.

That can be done by switching each pointer to the other list once it reaches the end.

## Approach
Use two pointers, one starting at each head.

- Move both pointers one step at a time.
- When a pointer reaches the end of its list, redirect it to the head of the other list.
- If the lists intersect, the two pointers will meet at the intersection node.
- If they do not intersect, both pointers will eventually become `null` at the same time.

## Why It Works
Each pointer traverses exactly the same total distance: the length of list A plus the length of list B.

If there is an intersection, the shared tail cancels out the difference in list lengths, so the pointers meet at the first common node.

If there is no intersection, both pointers finish the full combined length and end at `null` together.

## Complexity
- Time: `O(m + n)`
- Space: `O(1)`

## Python
```python
class Solution:
    def getIntersectionNode(self, headA, headB):
        if not headA or not headB:
            return None

        a = headA
        b = headB

        while a != b:
            a = a.next if a else headB
            b = b.next if b else headA

        return a
```

## Java
```java
class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }

        ListNode a = headA;
        ListNode b = headB;

        while (a != b) {
            a = (a != null) ? a.next : headB;
            b = (b != null) ? b.next : headA;
        }

        return a;
    }
}
```

## C++
```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = (a != nullptr) ? a->next : headB;
            b = (b != nullptr) ? b->next : headA;
        }

        return a;
    }
};
```