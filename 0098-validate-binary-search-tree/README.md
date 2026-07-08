# 0098 - Validate Binary Search Tree

## Problem
Given the root of a binary tree, determine whether it is a valid binary search tree.

A valid BST must satisfy these rules:
- every node in the left subtree is strictly smaller than the node value
- every node in the right subtree is strictly larger than the node value
- both subtrees must also be valid BSTs

## Key Insight
A BST must produce values in strictly increasing order during an inorder traversal.

That gives a simple way to check the tree without comparing every node to every other node.

## Approach
Traverse the tree inorder while keeping track of the previously visited value.

- Visit the left subtree.
- Check that the current node value is greater than the previous value.
- Visit the right subtree.

If any value is not greater than the previous value, the tree is not a valid BST.

## Why It Works
An inorder traversal of a valid BST visits nodes from smallest to largest.

If the sequence ever stops being strictly increasing, then some node violates the BST ordering rule.

## Complexity
- Time: `O(n)`
- Space: `O(h)`

Here `h` is the height of the tree.

## Python
```python
class Solution:
    def isValidBST(self, root):
        self.prev = None

        def inorder(node):
            if not node:
                return True

            if not inorder(node.left):
                return False
            if self.prev is not None and node.val <= self.prev:
                return False

            self.prev = node.val
            return inorder(node.right)

        return inorder(root)
```

## Java
```java
class Solution {
    private Long prev = null;

    public boolean isValidBST(TreeNode root) {
        return inorder(root);
    }

    private boolean inorder(TreeNode node) {
        if (node == null) {
            return true;
        }

        if (!inorder(node.left)) {
            return false;
        }
        if (prev != null && node.val <= prev) {
            return false;
        }

        prev = (long) node.val;
        return inorder(node.right);
    }
}
```

## C++
```cpp
class Solution {
private:
    long long prev;
    bool hasPrev;

public:
    bool isValidBST(TreeNode* root) {
        prev = 0;
        hasPrev = false;
        return inorder(root);
    }

private:
    bool inorder(TreeNode* node) {
        if (node == nullptr) {
            return true;
        }

        if (!inorder(node->left)) {
            return false;
        }
        if (hasPrev && node->val <= prev) {
            return false;
        }

        prev = node->val;
        hasPrev = true;
        return inorder(node->right);
    }
};
```