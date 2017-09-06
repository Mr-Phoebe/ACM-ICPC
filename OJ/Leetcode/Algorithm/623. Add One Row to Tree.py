# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def addOneRow(self, root, v, d):
        """
        :type root: TreeNode
        :type v: int
        :type d: int
        :rtype: TreeNode
        """
        def dfs(root, depth):
            if not root: return
            if depth == d - 1:
                left = root.left
                right = root.right
                root.left = TreeNode(v)
                root.left.left = left
                root.right = TreeNode(v)
                root.right.right = right
                return
            dfs(root.left, depth + 1)
            dfs(root.right, depth + 1)
        
        if d == 1:
            head = TreeNode(v)
            head.left = root
            root = head
        else:
            dfs(root, 1)
        return root