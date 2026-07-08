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