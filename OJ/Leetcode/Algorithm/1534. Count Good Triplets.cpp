class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(abs(arr[i] - arr[j]) <= a) {
                    for(int k = j+1; k < n; k++) {
                        if(abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};