# 0104 - Maximum Depth of Binary Tree

## Problem
Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## Key Insight
The depth of a tree is one plus the maximum depth of its left and right subtrees.

That makes the problem a direct recursive definition.

## Approach
Use recursion to compute the depth of each subtree.

- If the current node is `null`, the depth is `0`.
- Otherwise, compute the depth of the left subtree and the right subtree.
- Return `1 + max(leftDepth, rightDepth)`.

## Why It Works
Every path from the root to a leaf must go through either the left subtree or the right subtree.

By taking the larger of those two depths and adding one for the current node, the recursion exactly matches the definition of maximum depth.

## Complexity
- Time: `O(n)`
- Space: `O(h)`

## Python
```python
class Solution:
    def maxDepth(self, root):
        if not root:
            return 0

        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
```

## Java
```java
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}
```

## C++
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```