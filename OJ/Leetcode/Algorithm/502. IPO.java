class Solution {
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        PriorityQueue<int[]> q1 = new PriorityQueue<>((a, b) -> (a[0] - b[0]));
        PriorityQueue<int[]> q2 = new PriorityQueue<>((a, b) -> (b[1] - a[1]));

        for(int i = 0; i < Profits.length; i++)
        {
            q1.add(new int[] {Capital[i], Profits[i]});
        }

        for(int i = 0; i < k; i++)
        {
            while(!q1.isEmpty() && q1.peek()[0] <= W) {
                q2.add(q1.poll());
            }

            if(q2.isEmpty())
                break;

            W += q2.poll()[1];
        }

        return W;
    }
}
