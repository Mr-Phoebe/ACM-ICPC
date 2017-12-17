#include<iostream>  
#include<string>  
#include<queue>  
#include<algorithm>  
using namespace std;  
int n, m;  
const int MAXN = 1e3 + 7;  
const int mod = 1e9 + 7;  
int limit[30];//每个字母使用限制  
long long dp[MAXN];//每个字符串的最多匹配方式  
int f[MAXN];//分配出的最少字串数  
char s[MAXN];//字符串  
  
int check(int i, int j)//检查序列是否合法  
{  
    int l = j - i + 1;//i~j之间字符数，包含i，j  
    for (int k = i; k <= j; k++)  
    {  
        if (limit[s[k] - 'a']<l)
            return 0;  
    }  
    return 1;  
}  
  
int main()  
{  
    int i, j;  
    while (cin >> n) {  
        cin >> s + 1;  
        for (i = 0; i < 26; i++)  
            cin >> limit[i];  
        int MAX = 0;  
        dp[0] = 1;  
        for (i = 1; i <= n; i++)//长度为i  
        {  
            f[i] = 1e9;  
            for (j = 1; j <= i; j++)//长度  
            {  
                if (check(i - j + 1, i))//后面的当前序列合法  
                {  
                    dp[i] = (dp[i] + dp[i - j]) % mod;//前i个字符分开的方法数  
                    f[i] = min(f[i], f[i - j] + 1);//最小字串数  
                    MAX = max(MAX, j);//最长字节  
                }  
            }  
        }  
        cout << dp[n] << endl;  
        cout << MAX << endl;  
        cout << f[n] << endl;  
    }  
    return 0;  
}  