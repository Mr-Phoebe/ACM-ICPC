#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=100+10;
int mat[maxn][maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&mat[i][j]);
    int ans=inf,sum,tmp;
    if(n>k)
    {
        for(int x=0;x<n;++x)
        {
            sum=0;
            for(int i=0;i<n;++i)
            {
                tmp=0;
                for(int j=0;j<m;++j)
                    tmp+=mat[i][j]^mat[x][j];
                sum+=min(tmp,m-tmp);
            }
            ans=min(ans,sum);
        }
    }
    else
    {
        for(int x=0;x<(1<<n);++x)
        {
            sum=0;
            for(int j=0;j<m;++j)
            {
                tmp=0;
                for(int i=0;i<n;++i)
                    tmp+=mat[i][j]^((x>>i)&1);
                sum+=min(tmp,n-tmp);
            }
            ans=min(ans,sum);
        }
    }
    if(ans>k) ans=-1;
    printf("%d\n",ans);
    return 0;
}
