/*
* @Author: Haonan Wu
* @Date:   2017-09-25 11:16:40
* @Last Modified by:   Haonan Wu
* @Last Modified time: 2017-09-25 11:23:43
*/

/* The read4 API is defined in the parent class Reader4.  
      int read4(char[] buf); */   

int read4(char *buf);  
class Solution{  
public:  
    int read(char *buf, int n){  
        for(int i = 0; i < n; i += 4){
            char[] tmp = new char[4];
            int num = read4(tmp);
            System.arraycopy(tmp, 0, buf, i, Math.min(num, n - i));
            if(num < 4) return Math.min(i + num, n);
        }
        return n;
    }  
};  
