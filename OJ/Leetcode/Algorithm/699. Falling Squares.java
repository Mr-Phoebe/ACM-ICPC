class Solution {
    class Node {
        public int l, r;
        public int max, value;
        public Node left, right;


        public Node(int l, int r, int max, int val) {
            this.l = l;
            this.r = r;
            this.max = max;
            this.value = val;
            this.right = null;
            this.left = null;
        }
    }

    private boolean intersect(Node n, int l, int r) {
        if (r <= n.l || l >= n.r) {
            return false;
        }
        return true;
    }

    private Node insert(Node root, int l, int r, int val) {
        if(root == null)
        {
            return new Node(l, r, r, val);
        }
        if(l <= root.l)
        {
            root.left = insert(root.left, l, r, val);
        }
        else
        {
            root.right = insert(root.right, l, r, val);
        }
        root.max = Math.max(r, root.max);
        return root;
    }

    private int query(Node root, int l, int r) {
        if(root == null || l >= root.max) {
            return 0;
        }

        int ans = 0;
        if(intersect(root, l, r)) {
            ans = root.value;
        }

        ans = Math.max(ans, query(root.left, l, r));

        if(r > root.l) {
            ans = Math.max(ans, query(root.right, l, r));
        }

        return ans;
    }

    public List<Integer> fallingSquares(int[][] positions) {
        List<Integer> ans = new ArrayList<>();
        Node root = null;
        int prev = 0;

        for (int i = 0; i < positions.length; i++) {
            int l = positions[i][0];
            int r = positions[i][0] + positions[i][1];
            int currentHeight = query(root, l, r);
            root = insert(root, l, r, currentHeight + positions[i][1]);
            prev = Math.max(prev, currentHeight + positions[i][1]);
            ans.add(prev);
        }
        return ans;
    }
}
