#include<bits/stdc++.h>

using namespace std;

const int MAXN=500005;

struct Node
{
    int l,r;
};
bool cmp(Node a,Node b)
{
    if(a.r==b.r)return a.l<b.l;
    return a.r<b.r;
}
Node p[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d",&p[i].l,&p[i].r);
    sort(p,p+n,cmp);
    int ans = 0;
    int last = -1;
    for(int i=0; i<n; i++)
    {
        if(p[i].l>last)
        {
            ans++;
            last = p[i].r;
        }
    }
    printf("%d\n",ans);
    return 0;
}
