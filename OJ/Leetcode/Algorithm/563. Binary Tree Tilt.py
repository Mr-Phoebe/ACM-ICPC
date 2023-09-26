# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans = 0
    def helper(self, root: Optional[TreeNode])-> Optional[int]:
        sum = root.val

        ret1 = ret2 = None
        if root.left:
            ret1 = self.helper(root.left)
            sum += ret1
        
        if root.right:
            ret2 = self.helper(root.right)
            sum += ret2

        ret1 = ret1 or 0
        ret2 = ret2 or 0
        self.ans = self.ans + abs(ret1 - ret2)
        return sum

    def findTilt(self, root: Optional[TreeNode]) -> int:
        if not root:
            return self.ans
        
        self.helper(root)

        return self.ans