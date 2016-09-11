/**************************************************
 * Author     : xiaohao Z
 * Blog     : http://www.cnblogs.com/shu-xiaohao/
 * Last modified : 2014-04-17 23:25
 * Filename     : RCC_2014_W_B.cpp
 * Description     : 
 * ************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned int,unsigned int> puu;
typedef pair<int, double> pid;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1E-6;
const int LEN = 21;
ll dp[1<<21];
struct F{
    int cost, mon, st;
}f[101];

bool cmp(F a, F b){
    return a.mon < b.mon;
}

int main()
{
//    freopen("in.txt", "r", stdin);

    int n, m, b, tn, tc, tm, tmp; 
    while(scanf("%d%d%d", &n, &m, &b)!=EOF)
	{
        for(int i=0; i<n; i++)
		{
            scanf("%d%d%d", &f[i].cost, &f[i].mon, &tn);
            f[i].st = 0;
            for(int j=0; j<tn; j++)
			{
                scanf("%d", &tmp);
                f[i].st |= (1 << (tmp-1));
            }
        }
        sort(f, f+n, cmp);
        for(int i=0; i<(1<<21); i++)
			dp[i] = LINF;
        dp[0] = 0;
        ll ans = LINF;
        for(int i=0; i<n; i++)
		{
            for(int j=(1 << m)-1; j>=0; j--)
                dp[j|f[i].st] = min(dp[j|f[i].st], dp[j] + f[i].cost);
            ans = min(dp[(1<<m)-1]+(ll)f[i].mon*(ll)b, ans);
        }
        if(ans == LINF)
			printf("-1\n");
        else printf("%I64d\n", ans);
    }
    return 0;
}