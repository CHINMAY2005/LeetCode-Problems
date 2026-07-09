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