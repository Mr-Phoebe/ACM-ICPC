class Solution {
public:
    int punishmentNumber(int n) {
        int sum = 1;
        for (int i = 2; i <= n; ++i) {
            std::vector<int> num = toVec(i*i);
            if (canSumAs(0, i, 0, num) == 2) {
                sum += i*i;
            }
        }
        return sum;
    }

    std::vector<int> toVec(int n) {
        std::vector<int> res;
        while(n) {
            res.push_back(n%10);
            n/=10;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

    int canSumAs(int cur, int tar, int pos, std::vector<int>& num) {
        if (cur == tar && pos == num.size()) {
            return 2;
        }
        // cur > tar 
        if (cur > tar) {
            return 1;
        }
        // cur < && pos == num.size
        if (pos == num.size()) {
            return 0;
        }

        int step = 0;
        for (int i = pos; i < num.size(); ++i) {
            step = step * 10 + num[i];
            int status = canSumAs(cur + step, tar, i+1, num);
            if (status == 2) {
                return 2;
            }
            // already large
            if (status == 1) {
                return 0;
            }
        }
        return 0;
    }
};