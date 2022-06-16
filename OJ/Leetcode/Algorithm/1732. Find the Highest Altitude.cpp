class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int maxSum = 0;
        for(const auto& g : gain) {
            sum += g;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};