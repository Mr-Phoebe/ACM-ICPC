/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int ans;
    public void dfs(TreeNode root, String num) {
        if(root == null)
            return;
        if(root.left == null && root.right == null)
        {
            ans += Integer.parseInt(num + root.val);
            return;
        }
        if(root.left  != null)
            dfs(root.left,  num + root.val);
        if(root.right != null)
            dfs(root.right, num + root.val);
        return;
    }

    public int sumNumbers(TreeNode root) {
        ans = 0;
        dfs(root, "0");
        return ans;
    }
}
