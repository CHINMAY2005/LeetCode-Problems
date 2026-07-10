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