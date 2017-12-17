class Solution {
public:
    static bool canMeasureWater(int x, int y, int z) {
        if (x+y < z) return false;
        if (x==z || y==z || x+y==z) return true;
        return z%gcd(x, y) == 0;
    }
    static int gcd(int a, int b){
        while (b != 0) {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
};