public class Solution {  
    public int getSum(int a, int b) {  
        int c = a ^ b;  
        int d = (a & b) << 1;  
        while(d != 0){  
            a = d;  
            b = c;  
            c = a ^ b;  
            d = (a & b) << 1;   
        }  
        return c;  
    }  
} 