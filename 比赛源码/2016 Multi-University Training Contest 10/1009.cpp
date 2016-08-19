#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<map>
#define maxn 5008
#define maxl 10
using namespace std;

vector<int> edge[maxn+8];
int sg[maxn+8],vis[maxn+8];
int a[maxn+8];
map<int , int> M;

struct NIM
{
    int a[maxl];
    int num;
    NIM(){}
    NIM(int x)
    {
        num = 0;
        for (int i = maxl-1 ; i >= 0 ; i--)
            a[i] = x & 1,num = num * 3 + a[i],x>>=1;
    }
    void init(int x)
    {
        num = 0;
        for (int i = maxl-1 ; i >= 0 ; i--)
            a[i] = x & 1,num = num * 3 + a[i],x>>=1;
    }
    NIM operator + ( NIM k) const
    {
        NIM tmp;
        tmp.num = 0;
        for (int i = maxl - 1  ; i >= 0 ; i--)
            tmp.a[i] = (a[i] + k.a[i]) % 3,tmp.num = tmp.num * 3 + tmp.a[i];
        return tmp;
    }

    NIM operator - ( NIM k) const
    {
        NIM tmp;
        tmp.num = 0;
        for (int i = maxl - 1 ; i >= 0 ; i-- )
            tmp.a[i] = (a[i] - k.a[i] + 3) % 3,tmp.num = tmp.num * 3 + tmp.a[i];
        return tmp;
    }
}SG[maxn];

void get_sg(int v)
{
    if (sg[v] != -1) return;
    for (int i = 0 ; i < edge[v].size() ; i++ )
        get_sg(edge[v][i]);
    for (int i = 0 ; i < edge[v].size() ; i++)
        vis[ sg[edge[v][i]] ] = v;
    for (int i = 0 ; i < maxn ; i++)
        if (vis[i] != v)
        {
            sg[v] = i;
            return;
        }
}

int main()
{
    int n,m,k;
// freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
    while (~scanf("%d%d%d",&n,&m,&k))
    {
        int x,y;
        M.clear();
        memset(sg,-1,sizeof(sg));
        for (int i = 1 ; i <= n ; i++) edge[i].clear();
        for (int i = 1 ; i <= m ; i++)
            {
                scanf("%d%d",&x,&y);
                edge[x].push_back(y);
            }
        memset(vis,0,sizeof(vis));
        for (int i = 1 ; i <= n ; i++)
        {
            if (sg[i] == -1)
                get_sg(i);
            SG[i].init(sg[i]);
        }

        for (int i = 1 ; i <= k ; i++)
            scanf("%d",&a[i]);
        NIM sumsg(0);
        for (int i = 1 ; i <= k ; i++)
        {
            int v = a[i];
            sumsg = sumsg + SG[v];
        }

        int sum = 0;
        M[0] = 1;
        

        for (int i = 1 ; i <= k ; i++)
        {
            int v = a[i];
           
            for (int j = 0 ; j < edge[v].size() ; j++)
                {
                    NIM tmp(0);
                    tmp = tmp - sumsg + SG[v] - SG[edge[v][j]];
                    sum+=M[tmp.num];
                }

            for (int j = 0 ; j < edge[v].size() ; j++)
                M[ (SG[edge[v][j]] - SG[a[i]]).num ]++;
        }

        cout<<sum<<endl;
    }


    return 0;
}
