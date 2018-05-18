class Solution {
    private class City implements Comparable<City>{
        int id;
        int costFromSrc;
        int stopFromSrc;
        public City(int id, int costFromSrc, int stopFromSrc){
            this.id = id;
            this.costFromSrc = costFromSrc;
            this.stopFromSrc = stopFromSrc;
        }
        public boolean equals(City c){
            if(c instanceof City)
                return this.id == c.id;
            return false;
        }
        public int compareTo(City c){
            return this.costFromSrc - c.costFromSrc;
        }
    }
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[][] srcToDst = new int[n][n];
        for(int i = 0; i < flights.length; i++)
            srcToDst[flights[i][0]][flights[i][1]] = flights[i][2];

        PriorityQueue<City> minHeap = new PriorityQueue();
        minHeap.offer(new City(src,0,0));

        int[] cost = new int[n];
        Arrays.fill(cost, Integer.MAX_VALUE);
        cost[src] = 0;
        int[] stop = new int[n];
        Arrays.fill(stop, Integer.MAX_VALUE);
        stop[src] = 0;

        while(!minHeap.isEmpty()){
            City curCity = minHeap.poll();
            if(curCity.id == dst) continue;
            if(curCity.stopFromSrc == K + 1) continue;
            int[] nexts = srcToDst[curCity.id];
            for(int i = 0; i < n; i++){
                if(nexts[i] != 0){
                    int newCost = curCity.costFromSrc + nexts[i];
                    int newStop = curCity.stopFromSrc + 1;
                    if(newCost < cost[i]){
                        minHeap.offer(new City(i, newCost, newStop));
                        cost[i] = newCost;
                    }
                    if(newStop < stop[i]){
                        minHeap.offer(new City(i, newCost, newStop));
                        stop[i] = newStop;
                    }
                }
            }
        }

        return cost[dst] == Integer.MAX_VALUE? -1:cost[dst];
    }
}
