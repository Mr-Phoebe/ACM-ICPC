class Solution {
    struct Node {
        int idx;
        long processTime;
        Node(int idx, long processTime) {
            this->idx = idx;
            this->processTime = processTime;
        }
        bool operator < (const Node& r) const {
            if (processTime == r.processTime) {
                return idx > r.idx;
            }
            return processTime > r.processTime;
        }
    };
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); ++i) {
            tasks[i].push_back(i);
        }
        priority_queue<Node> q;
        sort(tasks.begin(), tasks.end(), cmp);
        long curTime = tasks[0][0];
        int curIndex = 0;
        vector<int> res;
        res.reserve(tasks.size());
        while(curIndex < tasks.size() || !q.empty()) {
            for(;curIndex < tasks.size(); ++curIndex) {
                if(curTime >= tasks[curIndex][0]) {
                    q.push(Node(tasks[curIndex][2], tasks[curIndex][1]));
                } else {
                    break;
                }
            }   
            if(!q.empty()) {
                Node curTask = q.top();
                q.pop();
                curTime += curTask.processTime;
                res.push_back(curTask.idx);
            } else {
                curTime = tasks[curIndex][0];
            }
        }

        return res;
    }
};