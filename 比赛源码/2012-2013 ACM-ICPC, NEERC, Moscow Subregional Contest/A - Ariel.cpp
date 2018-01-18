#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int m;

int score[10005];
int p0[10005];

vector<int> V[1050];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int y;
        int f[12];

        scanf("%d%d",&score[i],&y);

        for(int j=1;j<=y;j++)
            scanf("%d",&f[j]);

        int p = 0;

        for(int j=1;j<=y;j++)
            p |= (1 << (f[j]-1));

        p0[i] = p;
        V[p].push_back(score[i]);
    }

    for(int i=0;i< (1 << k);i++)
        sort(V[i].begin(),V[i].end());

    scanf("%d",&m);

    for(int cas=1;cas<=m;cas++)
    {
        int id,y;
        int h[12];
        scanf("%d%d",&id,&y);

        int ans = 0;

        for(int i=1;i<=y;i++)
        {
            scanf("%d",&h[i]);
        }

        for(int i=0;i< (1 << k);i++)
        {
            for(int j=1;j<=y;j++)
                if( (i & (1 << (h[j]-1))) != (p0[id] & (1 << (h[j]-1))) ) goto endLoop;

            ans += V[i].end() - upper_bound(V[i].begin(),V[i].end(),score[id]);

            endLoop:;
        }

        printf("%d\n",ans+1);
    }
    return 0;
}

