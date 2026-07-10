# 0145 - Binary Tree Postorder Traversal

## Problem
Given the root of a binary tree, return the postorder traversal of its nodes' values.

## Key Insight
Postorder traversal always visits the left subtree, then the right subtree, and finally the current node.

That order can be implemented with recursion or by reversing a modified preorder traversal.

## Approach
Use an iterative stack-based traversal.

- Start with the root on a stack.
- Pop a node, add its value to the result, and push its left child and then its right child.
- After all nodes are processed, reverse the collected values.

This produces postorder because reversing the modified preorder sequence turns root-right-left into left-right-root.

## Why It Works
A preorder-like traversal that processes root, then right, then left visits nodes in the opposite order of postorder.

Reversing that sequence therefore yields the exact left-right-root order required by postorder traversal.

## Complexity
- Time: `O(n)`
- Space: `O(h)`

## Python
```python
class Solution:
    def postorderTraversal(self, root):
        if not root:
            return []

        result = []
        stack = [root]

        while stack:
            node = stack.pop()
            result.append(node.val)

            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

        return result[::-1]
```

## Java
```java
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            result.add(node.val);

            if (node.left != null) {
                stack.push(node.left);
            }
            if (node.right != null) {
                stack.push(node.right);
            }
        }

        java.util.Collections.reverse(result);
        return result;
    }
}
```

## C++
```cpp
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);

            if (node->left != nullptr) {
                st.push(node->left);
            }
            if (node->right != nullptr) {
                st.push(node->right);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
```