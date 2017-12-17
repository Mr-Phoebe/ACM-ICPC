#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

#define maxn 100010
#define maxm 100010

using namespace std;

int n;
int a[maxn],b[maxn],c[maxn],mark[maxm];
vector<int> adj[maxm];

int main()
{
    for (int i=1;i<maxm;i++) adj[i].clear();
    for (int i=1;i<maxm;i++)
        for (int j=1;j<maxm/i;j++)
            adj[i*j].push_back(i);
    while (1){
    scanf("%d",&n);
    if (!n) break;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(mark,0,sizeof(mark));
    for (int i=1;i<=n;i++)
    {
        if (mark[a[i]]==0) b[i]=a[i];else b[i]=mark[a[i]];
        for (int j=0;j<adj[a[i]].size();j++)
        {
            int d=adj[a[i]][j];
            mark[d]=a[i];
        }
    }
    memset(mark,0,sizeof(mark));
    for (int i=n;i>=1;i--)
    {
        if (mark[a[i]]==0) c[i]=a[i];else c[i]=mark[a[i]];
        for (int j=0;j<adj[a[i]].size();j++)
        {
            int d=adj[a[i]][j];
            mark[d]=a[i];
        }
    }
    long long ans=0;
    for (int i=1;i<=n;i++)
        ans+=(long long)b[i]*(long long)c[i];
    printf("%I64d\n",ans);
    }
    return 0;
}
