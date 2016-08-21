#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

int p[10010];

inline int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

char atlas[105][105];

bool checkup(char x)
{
    return x == 'A' || x == 'B' || x == 'E' || x == 'G' || x == 'H' || x == 'J' || x == 'K';
}

bool checkleft(char x)
{
    return x == 'A' || x == 'C' || x == 'F' || x == 'G' || x == 'H' || x == 'I' || x == 'K';
}

bool checkdown(char x)
{
    return x == 'C' || x == 'D' || x == 'E' || x == 'H' || x == 'I' || x == 'J' || x == 'K';
}

bool checkright(char x)
{
    return x == 'B' || x == 'D' || x == 'F' || x == 'G' || x == 'I' || x == 'J' || x == 'K';
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m))
    {
        if(n < 0 || m < 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%s", atlas[i]);
        for(int i = 0; i < n*m; i++)
            p[i] = i;
        int cnt = n*m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int tmp, pnow = find(i*m+j);
                if(checkdown(atlas[i][j]) && i < n-1 && checkup(atlas[i+1][j]))
                {
                    tmp = find(i*m+m+j);
                    if(tmp != pnow)
                        cnt--, p[tmp] = pnow;
                }
                if(checkright(atlas[i][j]) && j < m-1 && checkleft(atlas[i][j+1]))
                {
                    tmp = find(i*m+j+1);
                    if(tmp != pnow)
                        cnt--, p[tmp] = pnow;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n*m; i++)
            if(p[i] == i)
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
