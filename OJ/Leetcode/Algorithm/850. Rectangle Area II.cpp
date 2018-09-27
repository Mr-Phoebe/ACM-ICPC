class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1000000000 + 7;
        vector<int> x = {0};
        for (auto r : rectangles) {
            x.push_back(r[0]);
            x.push_back(r[2]);
        }
        sort(x.begin(), x.end());
        vector<int>::iterator end_unique = unique(x.begin(), x.end());
        x.erase(end_unique, x.end());
        unordered_map<int, int> x_i;
        for (int i = 0; i < x.size(); ++i) {
            x_i[x[i]] = i;
        }
        vector<int> count(x.size(), 0);
        vector<vector<int>> L;
        for (auto r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            L.push_back({y1, x1, x2, 1});
            L.push_back({y2, x1, x2, -1});
        }
        sort(L.begin(), L.end());
        long long cur_y = 0, cur_x_sum = 0, area = 0;
        for (auto l : L) {
            long long  y = l[0], x1 = l[1], x2 = l[2], sig = l[3];
            area = (area + (y - cur_y) * cur_x_sum) % mod;
            cur_y = y;
            for (int i = x_i[x1]; i < x_i[x2]; i++)
                count[i] += sig;
            cur_x_sum = 0;
            for (int i = 0; i < x.size(); ++i) {
                if (count[i] > 0)
                    cur_x_sum += x[i + 1] - x[i];
            }
        }
        return area;
    }
};
