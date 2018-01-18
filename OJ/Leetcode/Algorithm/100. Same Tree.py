# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p == None and q == None:  
            return True  
        elif p == None or q == None:  
            return False  
      
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)  