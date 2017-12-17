# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root, False)
    def dfs(self, root, flag):
        if not root:
            return 0
        if not root.left and not root.right and flag:
            return root.val
        ans = self.dfs(root.left, True)
        ans += self.dfs(root.right, False)
        return ans
        