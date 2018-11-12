class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        while(!que.empty() && t - que.front() > 3000)
            que.pop();
        que.push(t);
        return que.size();
    }
private:
    queue<int> que;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
