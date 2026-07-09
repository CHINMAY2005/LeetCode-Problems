# 0101 - Symmetric Tree

## Problem
Given the root of a binary tree, determine whether it is a mirror of itself.

## Key Insight
Two subtrees are symmetric if the left child of one matches the right child of the other, and vice versa.

That makes this a recursive mirror-checking problem.

## Approach
Compare the tree with itself using a helper that checks two nodes for mirror symmetry.

- If both nodes are `null`, they match.
- If only one node is `null`, they do not match.
- If the values differ, they do not match.
- Otherwise compare the left subtree of one node with the right subtree of the other, and the right subtree of one node with the left subtree of the other.

## Why It Works
Symmetry requires every corresponding pair of nodes to match in value and placement.

The recursive helper checks exactly those mirrored pairs all the way down the tree, so it accepts precisely the trees that are symmetric.

## Complexity
- Time: `O(n)`
- Space: `O(h)`

## Python
```python
class Solution:
    def isSymmetric(self, root):
        def is_mirror(left, right):
            if not left and not right:
                return True
            if not left or not right:
                return False
            if left.val != right.val:
                return False

            return is_mirror(left.left, right.right) and is_mirror(left.right, right.left)

        return is_mirror(root, root)
```

## Java
```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

    private boolean isMirror(TreeNode left, TreeNode right) {
        if (left == null && right == null) {
            return true;
        }
        if (left == null || right == null) {
            return false;
        }
        if (left.val != right.val) {
            return false;
        }

        return isMirror(left.left, right.right) && isMirror(left.right, right.left);
    }
}
```

## C++
```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }

        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
```