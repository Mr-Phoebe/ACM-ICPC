# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfs(self, root, val):
        if not root:
            return -1
        if root.val != val:
            return root.val
        else:
            l = self.dfs(root.left, val)
            r = self.dfs(root.right, val)
            if l == val or l == -1:
                if r == val or r == -1:
                    return -1
                else:
                    return r
            else:
                if r == val or r == -1:
                    return l
                else:
                    return min(l ,r)

    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root, root.val)
