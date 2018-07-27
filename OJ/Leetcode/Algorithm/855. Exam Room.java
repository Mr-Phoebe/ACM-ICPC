class ExamRoom {

    class Interval
    {
        int x, y, dist;
        public Interval(int x, int y)
        {
            this.x = x;
            this.y = y;
            if(x == -1)
                this.dist = y;
            else if (y == N)
                this.dist = N - 1 - x;
            else
                this.dist = Math.abs(x - y) / 2;
        }
    }

    PriorityQueue<Interval> pq;
    int N;

    public ExamRoom(int N) {
        this.pq = new PriorityQueue<>((a, b) -> a.dist != b.dist? b.dist - a.dist : a.x - b.x);
        this.N = N;
        pq.add(new Interval(-1, N));
    }

    public int seat() {
        int ans = 0;
        Interval interval = pq.poll();
        if(interval.x == -1) ans = 0;
        else if(interval.y == N) ans = N - 1;
        else ans = (interval.x + interval.y) / 2;

        pq.offer(new Interval(interval.x, ans));
        pq.offer(new Interval(ans, interval.y));

        return ans;
    }

    public void leave(int p) {
        Interval head = null, tail = null;
        List<Interval> intervals = new ArrayList<>(pq);
        for (Interval interval : intervals)
        {
            if(interval.x == p) tail = interval;
            if(interval.y == p) head = interval;
            if(head != null && tail != null) break;
        }
        pq.remove(head);
        pq.remove(tail);
        pq.offer(new Interval(head.x, tail.y));
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
