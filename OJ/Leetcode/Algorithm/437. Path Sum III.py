# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfs(self, root, cur, sum):
        if not root:   return 0
        cur += root.val
        return self.dfs(root.right, cur, sum) + self.dfs(root.left, cur, sum) + (1 if cur == sum else 0)
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if not root:    return 0
        return self.dfs(root, 0, sum) + self.pathSum(root.right, sum) + self.pathSum(root.left, sum)
    
            