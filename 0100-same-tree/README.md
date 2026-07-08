# 0100 - Same Tree

## Problem
Given the roots of two binary trees, determine whether they are structurally identical and contain the same values.

## Key Insight
Two trees are the same only if their roots match and both corresponding subtrees match.

That makes this a simple recursive comparison problem.

## Approach
Compare the two trees node by node.

- If both nodes are `null`, they match.
- If only one is `null`, they do not match.
- If the values differ, they do not match.
- Otherwise compare the left children and the right children.

## Why It Works
The recursion checks exactly the structural and value equality required by the problem.

Every pair of corresponding nodes must match, and the base cases handle all ways the trees can diverge.

## Complexity
- Time: `O(n)`
- Space: `O(h)`

## Python
```python
class Solution:
    def isSameTree(self, p, q):
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val != q.val:
            return False

        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```

## Java
```java
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        if (p.val != q.val) {
            return false;
        }

        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
```

## C++
```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```