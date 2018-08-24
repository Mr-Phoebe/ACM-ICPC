#define vi vector<int>
class Solution {
public:
    int scheduleCourse(vector<vector<int> >& courses) {
        auto cmp = [](vi a, vi b){if(a[1] != b[1]) return a[1] < b[1]; return a[0] < b[0];};
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int, vector<int>, less<int> > qb;
        int n = courses.size();
        long long time = 0;
        for(int i = 0; i < n; i++)
        {
            time += courses[i][0];
            qb.push(courses[i][0]);
            if(time > courses[i][1])
            {
                time -= qb.top();
                qb.pop();
            }
        }
        return qb.size();
    }
};
