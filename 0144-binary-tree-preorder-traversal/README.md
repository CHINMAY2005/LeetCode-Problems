# 0144 - Binary Tree Preorder Traversal

## Problem
Given the root of a binary tree, return the preorder traversal of its nodes' values.

## Key Insight
Preorder traversal always visits the current node first, then the left subtree, then the right subtree.

That order can be implemented cleanly with either recursion or an explicit stack.

## Approach
Use an iterative stack-based traversal.

- Start with the root on the stack.
- Pop the top node, record its value, and push its right child and then its left child.
- Continue until the stack is empty.

Pushing the right child before the left child ensures the left child is processed first.

## Why It Works
The stack stores nodes in the reverse of the order they should be visited.

By always processing the current node before its children and pushing right before left, the traversal exactly matches preorder order.

## Complexity
- Time: `O(n)`
- Space: `O(h)`

## Python
```python
class Solution:
    def preorderTraversal(self, root):
        if not root:
            return []

        result = []
        stack = [root]

        while stack:
            node = stack.pop()
            result.append(node.val)

            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        return result
```

## Java
```java
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;

class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            result.add(node.val);

            if (node.right != null) {
                stack.push(node.right);
            }
            if (node.left != null) {
                stack.push(node.left);
            }
        }

        return result;
    }
}
```

## C++
```cpp
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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

            if (node->right != nullptr) {
                st.push(node->right);
            }
            if (node->left != nullptr) {
                st.push(node->left);
            }
        }

        return result;
    }
};
```