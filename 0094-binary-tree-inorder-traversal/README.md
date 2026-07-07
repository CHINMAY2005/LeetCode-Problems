# 0094 - Binary Tree Inorder Traversal

## Problem
Given the root of a binary tree, return the inorder traversal of its nodes' values.

## Key Insight
Inorder traversal always visits the left subtree, then the node itself, then the right subtree.

That order can be implemented recursively or with an explicit stack.

## Approach
Use a stack to simulate the recursive call stack.

- Move left as far as possible, pushing nodes along the way.
- Pop the top node, record its value, and then move to its right child.
- Repeat until both the current pointer and the stack are empty.

## Why It Works
The stack always stores the path to the next node that still needs to be visited after its left subtree has been exhausted.

This exactly matches the inorder rule, so every node is visited once in the correct order.

## Complexity
- Time: `O(n)`
- Space: `O(h)`

Here `h` is the height of the tree.

## Python
```python
class Solution:
    def inorderTraversal(self, root):
        result = []
        stack = []
        current = root

        while current or stack:
            while current:
                stack.append(current)
                current = current.left

            current = stack.pop()
            result.append(current.val)
            current = current.right

        return result
```

## Java
```java
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode current = root;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            current = stack.pop();
            result.add(current.val);
            current = current.right;
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            result.push_back(current->val);
            current = current->right;
        }

        return result;
    }
};
```