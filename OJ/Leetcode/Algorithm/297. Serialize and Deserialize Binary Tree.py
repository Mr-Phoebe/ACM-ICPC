# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "# "
        else:
            return str(root.val) + " " + serialize(root.left) + serialize(root.right)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def decode():
            val = next(vals)
            if val == "#":
                return None
            else:
                root = TreeNode(int(val))
                root.left = decode()
                root.right = decode()
                return root
        
        vals = iter(data.split())
        return decode()
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))