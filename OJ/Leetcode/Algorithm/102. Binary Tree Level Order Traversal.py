# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans, layer = [], [root]
        while root and layer:
            ans.append([node.val for node in layer])
            layer = [kid for node in layer for kid in [node.left, node.right] if kid]
        return ans
