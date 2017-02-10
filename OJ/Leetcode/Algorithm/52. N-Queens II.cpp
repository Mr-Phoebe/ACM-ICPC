class Solution {  
public:  
    int totalNQueens(int n) {  
        limit = (1 << n) - 1;  
        return nQueens(0, 0, 0);  
    }  
      
private:  
    int nQueens(int res, int ld, int rd)  
    {  
        if (res != limit)  
        {  
            int pos = limit & ~(res | ld | rd);  
            int result = 0;  
            while (pos)  
            {  
                int p = pos & -pos;  
                pos -= p;  
                result += nQueens(res + p, (ld + p) << 1, (rd + p) >> 1);  
            }  
            return result;  
        }  
        return 1;  
    }  
      
    int limit;  
};  