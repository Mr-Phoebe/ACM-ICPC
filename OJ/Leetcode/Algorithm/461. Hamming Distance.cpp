class Solution {
public:
    int hammingDistance(int x, int y) {
        int xOR = x^y;
        return numberOfOnes(xOR);
    }

    int numberOfOnes(int n) {
        int result = 0;
        while(n > 0){
            result += 1;
            n -= n & -n;
        }
        return result;
    }
};
