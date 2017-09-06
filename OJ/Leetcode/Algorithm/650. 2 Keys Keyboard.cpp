class Solution {
public:
    int minSteps(int n) {
        int s = 0;
        for (int d = 2; d <= n; d++) {
            while (n % d == 0) {
                s += d;
                n /= d;
            }
        }
        return s;
    }
};
// this is a greedy solution, but I don't find the proof of this method
