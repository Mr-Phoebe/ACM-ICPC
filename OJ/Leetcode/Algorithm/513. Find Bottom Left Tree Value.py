
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfs(self, root, level):
        if not root:
            return;
        if level > self.max_level:
            self.max_level = level
            self.val = root.val
        self.dfs(root.left, level + 1)
        self.dfs(root.right, level + 1)

    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = None
        self.max_level = 0
        self.dfs(root, 1)
        return self.val


