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