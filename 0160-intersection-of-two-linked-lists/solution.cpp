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