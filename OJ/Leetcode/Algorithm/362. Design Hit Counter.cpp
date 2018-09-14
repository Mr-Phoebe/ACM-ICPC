class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        total_cnt = 0;
        cur_timestamp = -1;
        cur_cnt = 0;
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if(cur_timestamp == -1 || timestamp > cur_timestamp)
        {
            if(cur_timestamp + gap > timestamp)
            {
                que.push(make_pair(cur_timestamp, cur_cnt));
                total_cnt += cur_cnt;
            }
            while(!que.empty() && que.front().first + gap <= timestamp)
            {
                auto item = que.front();
                que.pop();
                total_cnt -= item.second;
            }
            cur_timestamp = timestamp;
            cur_cnt = 1;
        }
        else if(timestamp == cur_timestamp)
        {
            cur_cnt++;
        }
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        if(cur_timestamp == -1 || timestamp > cur_timestamp)
        {
            if(cur_timestamp + gap > timestamp)
            {
                que.push(make_pair(cur_timestamp, cur_cnt));
                total_cnt += cur_cnt;
            }
            while(!que.empty() && que.front().first + gap <= timestamp)
            {
                auto item = que.front();
                que.pop();
                total_cnt -= item.second;
            }
            cur_timestamp = timestamp;
            cur_cnt = 0;
        }
        return total_cnt;
    }
private:
    queue<pair<int, int> > que;
    int total_cnt;
    int cur_timestamp, cur_cnt;
    const int gap = 60 * 5;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
