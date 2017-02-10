/*
* @Author: HaonanWu
* @Date:   2017-02-10 19:49:28
* @Last Modified by:   HaonanWu
* @Last Modified time: 2017-02-10 19:49:34
*/

class Solution {  
public:  
    vector<vector<string>> solveNQueens(int n) {  
        limit = (1 << n) - 1;  
        vector<string> vec(n, string(n, '.'));// 初始化一个全是'.'的vector，用来保存尝试结果  
        nQueue(0, 0, 0, 0, vec);// 参数k初始化为0，表示第0行  
        return result;  
    }  
      
private:  
    // 第4个参数k表示尝试的行数  
    void nQueue(long res, long ld, long rd, int k, vector<string>& vec)  
    {  
        if (res != limit)  
        {  
            int pos = limit & ~(res | ld | rd);  
            while (pos)  
            {  
                int p = pos & -pos;  
                pos -= p;  
                /** 
                 * pos = 2^t0 + 2^t1 + 2^t2 + ... (t0 < t1 < t2 < ...) 
                 * 则p = 2^t0，log2(p) = t0 
                 * t0则为可放置皇后的列 
                 */  
                vec[k][log2(p)] = 'Q';// 在第k行第t0列尝试放置一个皇后  
                nQueue(res + p, (ld + p) << 1, (rd + p) >> 1, k + 1, vec);// k + 1 : 继续进行下一行的尝试  
                vec[k][log2(p)] = '.';// 因为参数是引用，所以此处要复原vec  
            }  
        }  
        else result.push_back(vec);// 找到一个解，添加到结果中  
    }  
  
    vector<vector<string>> result;  
    int limit;  
};  