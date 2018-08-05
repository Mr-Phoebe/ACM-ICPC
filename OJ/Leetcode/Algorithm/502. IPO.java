class Solution {
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        PriorityQueue<int[]> q1 = new PriorityQueue<>((a, b) -> (a[0] - a[1]));
        PriorityQueue<int[]> q2 = new PriorityQueue<>((a, b) -> (b[1] - b[0]));

        for(int i = 0; i < Profits.length; i++) {
            q2.add(new int[] {Capital[i], Profits[i]});
        }

        for(int i = 0; i < k; i++)
        {
            while(!q2.isEmpty() && q2.peek()[0] <= W) {
                q1.add(q2.poll());
            }

            if(q1.isEmpty())
                break;

            W += q1.poll()[1];
        }

        return W;
    }
}
