# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        exists = set()
        def dfs(root):
            if root is None:
                return False
            if k - root.val in exists:
                return True
            else:
                exists.add(root.val)
                return dfs(root.left) or dfs(root.right)
        return dfs(root)
