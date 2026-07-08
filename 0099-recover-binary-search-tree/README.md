# 0099 - Recover Binary Search Tree

## Problem
Given the root of a binary search tree, two of the nodes were swapped by mistake.

Restore the tree without changing its structure.

## Key Insight
In a valid BST, an inorder traversal is sorted.

If two nodes are swapped, the inorder order will contain one or two inversions that reveal the misplaced nodes.

## Approach
Perform an inorder traversal and track the previous node.

- When a previous node is larger than the current node, an inversion has been found.
- The first misplaced node is the previous node from the first inversion.
- The second misplaced node is the current node from the last inversion.

After the traversal, swap the values of the two misplaced nodes.

## Why It Works
The swapped nodes are the only reason the inorder sequence is not sorted.

The first inversion identifies the larger misplaced value, and the last inversion identifies the smaller misplaced value, so swapping them restores the BST ordering.

## Complexity
- Time: `O(n)`
- Space: `O(h)`

## Python
```python
class Solution:
    def recoverTree(self, root):
        self.first = None
        self.second = None
        self.prev = None

        def inorder(node):
            if not node:
                return

            inorder(node.left)

            if self.prev and self.prev.val > node.val:
                if not self.first:
                    self.first = self.prev
                self.second = node
            self.prev = node

            inorder(node.right)

        inorder(root)
        self.first.val, self.second.val = self.second.val, self.first.val
```

## Java
```java
class Solution {
    private TreeNode first = null;
    private TreeNode second = null;
    private TreeNode prev = null;

    public void recoverTree(TreeNode root) {
        inorder(root);
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }

    private void inorder(TreeNode node) {
        if (node == null) {
            return;
        }

        inorder(node.left);

        if (prev != null && prev.val > node.val) {
            if (first == null) {
                first = prev;
            }
            second = node;
        }
        prev = node;

        inorder(node.right);
    }
}
```

## C++
```cpp
class Solution {
private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;

public:
    void recoverTree(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        prev = nullptr;
        inorder(root);
        swap(first->val, second->val);
    }

private:
    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left);

        if (prev != nullptr && prev->val > node->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = node;
        }
        prev = node;

        inorder(node->right);
    }
};
```