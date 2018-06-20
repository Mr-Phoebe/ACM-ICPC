/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode Root) {
        TreeLinkNode root = Root;
        while(root != null)
        {
            TreeLinkNode cur = root;
            while(cur != null)
            {
                if(cur.left != null)
                {
                    cur.left.next = cur.right;
                    if(cur.next != null)
                        cur.right.next = cur.next.left;
                }
                cur = cur.next;
            }
            root = root.left;
        }
    }
}
