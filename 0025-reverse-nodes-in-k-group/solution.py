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
