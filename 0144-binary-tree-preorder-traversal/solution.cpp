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