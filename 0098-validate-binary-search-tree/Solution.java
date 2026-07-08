class Solution {
    private Long prev = null;

    public boolean isValidBST(TreeNode root) {
        return inorder(root);
    }

    private boolean inorder(TreeNode node) {
        if (node == null) {
            return true;
        }

        if (!inorder(node.left)) {
            return false;
        }
        if (prev != null && node.val <= prev) {
            return false;
        }

        prev = (long) node.val;
        return inorder(node.right);
    }
}