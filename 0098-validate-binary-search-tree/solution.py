class Solution:
    def isValidBST(self, root):
        self.prev = None

        def inorder(node):
            if not node:
                return True

            if not inorder(node.left):
                return False
            if self.prev is not None and node.val <= self.prev:
                return False

            self.prev = node.val
            return inorder(node.right)

        return inorder(root)