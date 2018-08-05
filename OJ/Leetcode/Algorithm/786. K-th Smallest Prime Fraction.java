class Solution {
 public int[] kthSmallestPrimeFraction(int[] a, int k) {
        int n = a.length;
        // 0: numerator idx, 1: denominator idx
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>()
        {
            @Override
            public int compare(int[] o1, int[] o2)
            {
                int s1 = a[o1[0]] * a[o2[1]];
                int s2 = a[o2[0]] * a[o1[1]];
                return s1 - s2;
            }
        });
        for (int i = 0; i < n-1; i++)
            pq.add(new int[]{i, n-1});
        for (int i = 0; i < k-1; i++)
        {
            int[] pop = pq.remove();
            int ni = pop[0];
            int di = pop[1];
            if (pop[1] - 1 > pop[0])
            {
                pop[1]--;
                pq.add(pop);
            }
        }

        int[] peek = pq.peek();
        return new int[]{a[peek[0]], a[peek[1]]};
    }
}
