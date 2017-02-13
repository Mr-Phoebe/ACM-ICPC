# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        dict={0:[None],1:[TreeNode(1)]}
        def TreeCopy(root,n):
            if not root:
                return None
            root1,root1.left,root1.right=TreeNode(root.val+n),TreeCopy(root.left,n),TreeCopy(root.right,n)
            return root1
        def GenerateBST(n):
            if dict.has_key(n):
                return dict[n]
            list=[]
            for ii in range(1,n+1):
                listLeft,listRight=GenerateBST(ii-1),GenerateBST(n-ii)
                for treeLeft in listLeft:
                    for treeRight in listRight:
                        tmp,tmp.left,tmp.right=TreeNode(ii),TreeCopy(treeLeft,0),TreeCopy(treeRight,ii)
                        list.append(tmp)
            dict[n]=list
            return list
        return GenerateBST(n)