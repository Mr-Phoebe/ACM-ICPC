# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root:
            return []
        l = self.binaryTreePaths(root.left)
        r = self.binaryTreePaths(root.right)
        if l == [] and r == []:
            return [str(root.val)]
        ans = set()
        for s in l:
            ans.add(str(root.val) + "->" + s)
        for s in r:
            ans.add(str(root.val) + "->" + s)
        return list(ans)
            
