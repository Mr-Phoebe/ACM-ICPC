#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<string>  
#include<algorithm>  
#include<map>  
#include<queue>  
#include<set>  
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
const int maxm=100000+10;  
struct Edge  
{  
    int u,v;  
}edges[maxm],ee[maxm];  
struct Node  
{  
    int u,d;  
    bool operator < (const Node &a) const  
    {  
        return d>a.d;  
    }  
};  
Node node[maxn],nd[maxn];  
int flag,n,m,mm;  
void getother(int s,int z)  
{  
    for(int i=0;i<n;++i)  
      nd[i]=node[i];  
    for(int i=0;i<m;++i)  
      ee[i]=edges[i];  
    int tm=nd[z].u;  
    nd[z].u=nd[z+1].u;  
    nd[z+1].u=tm;  
    mm=m;  
    for(int i=s;i<n;++i)  
    {  
        if(i!=s) sort(nd+i,nd+i+n-i);  
        if(nd[i].d==0) break;  
        int p=i+nd[i].d;  
        if(p>=n||nd[p].d<1)  
        {  
            flag=-1;  
            return ;  
        }  
        for(int j=1;j<=nd[i].d;++j)  
        {  
            ee[mm].u=nd[i].u;  
            ee[mm].v=nd[i+j].u;  
            mm++;  
            nd[i+j].d--;  
        }  
    }  
}  
void solve()  
{  
    for(int i=0;i<n;++i)  
    {  
        sort(node+i,node+i+n-i);  
        if(node[i].d==0) break;  
        int p=i+node[i].d;  
        if(p>=n||node[p].d<1)  
        {  
            flag=-1;  
            return ;  
        }  
        if(flag==0&&p+1<n&&node[p].d==node[p+1].d)  
        {  
            flag=1;  
            getother(i,p);  
            if(flag==-1) return ;  
        }  
        for(int j=1;j<=node[i].d;++j)  
        {  
            edges[m].u=node[i].u;  
            edges[m].v=node[i+j].u;  
            m++;  
            node[i+j].d--;  
        }  
    }  
}  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout);  
    while(~scanf("%d",&n))  
    {  
        for(int i=0;i<n;++i)  
        {  
            scanf("%d",&node[i].d);  
            node[i].u=i;  
        }  
        flag=0;  
        m=mm=0;  
        solve();  
        if(flag==-1) printf("IMPOSSIBLE\n");  
        else if(flag==0)  
        {  
            printf("UNIQUE\n");  
            printf("%d %d\n",n,m);  
            for(int i=0;i<m;++i)  
            {  
                if(i) printf(" ");  
                printf("%d",edges[i].u+1);  
            }  
            printf("\n");  
            for(int i=0;i<m;++i)  
            {  
                if(i) printf(" ");  
                printf("%d",edges[i].v+1);  
            }  
            printf("\n");  
        }  
        else  
        {  
            printf("MULTIPLE\n");  
            printf("%d %d\n",n,m);  
            for(int i=0;i<m;++i)  
            {  
                if(i) printf(" ");  
                printf("%d",edges[i].u+1);  
            }  
            printf("\n");  
            for(int i=0;i<m;++i)  
            {  
                if(i) printf(" ");  
                printf("%d",edges[i].v+1);  
            }  
            printf("\n");  
            printf("%d %d\n",n,m);  
            for(int i=0;i<m;++i)  
            {  
                if(i) printf(" ");  
                printf("%d",ee[i].u+1);  
            }  
            printf("\n");  
            for(int i=0;i<m;++i)  
            {  
                if(i) printf(" ");  
                printf("%d",ee[i].v+1);  
            }  
            printf("\n");  
        }  
    }  
    return 0;  
}  