#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#define MAXN 30005

using namespace std;

map<string,int> M;
stack<int> fa;
string reM[MAXN];

int n,m;

int p[MAXN][20];
int deep[MAXN];
int num_son[MAXN];

int head[MAXN],nxt[MAXN],node[MAXN];
int Index;

int tp[MAXN];

void addedge(int u,int v)
{
    Index++;
    nxt[Index] = head[u];
    node[Index] = v;
    head[u] = Index;
}

void init()
{
    Index = 0;
    M.clear();
    while(!fa.empty()) fa.pop();

    memset(head,0,sizeof(head));
    memset(nxt,0,sizeof(nxt));
    memset(num_son,0,sizeof(num_son));

    deep[1] = 0;
    p[1][0] = 1;
}

void dfs(int ret,int fa=-1)
{
    for(int j=1;j<20;j++)
        p[ret][j] = p[p[ret][j-1]][j-1];

    for(int o=head[ret];o;o=nxt[o])
        if(node[o] != fa)
        {
            num_son[ret]++;
            p[node[o]][0] = ret;
            deep[node[o]] = deep[ret] + 1;
            dfs(node[o],ret);
        }
}

int getLca(int u,int v)
{
    if(deep[u] > deep[v])
        swap(u,v);

    for(int delta = deep[v]-deep[u],i=0;delta!=0;delta>>=1,++i)
        if(delta & 1) v = p[v][i];

    if(u == v) return u;

    for(int i=19;i>=0;i--)
    {
        if(p[u][i] == p[v][i]) continue;
        u = p[u][i],v = p[v][i];
    }
    return p[u][0];
}

struct shit
{
    string a;
    int b;

    shit(){}
    shit(string aa,int bb):a(aa),b(bb){}

    bool operator < (const shit &o) const
    {
        return a < o.a;
    }
};


void work(int ret)
{
    for(int i=0;i<deep[ret];i++) printf(".");
    cout<<reM[ret];
    printf("\n");

    vector<shit> V;

    for(int o=head[ret];o;o=nxt[o])
        V.push_back(shit(reM[node[o]],node[o]));
    sort(V.begin(),V.end());

    for(int i=0;i<V.size();i++)
        work(V[i].b);
}

int main()
{
    while(~scanf("%d",&n))
    {
        if(n == 0) break;

        init();

        int pre_dots = 0;

        for(int i=1;i<=n;i++)
        {
            char c[65];
            scanf("%s",c);

            int num_dots = 0;
            while(c[num_dots] == '.') num_dots++;


            M.insert(make_pair(string(c + num_dots),i));
            reM[i] = string(c + num_dots);

            if(num_dots > pre_dots) fa.push(i-1);
            if(num_dots < pre_dots)
            {
                for(int kkk=num_dots;kkk<pre_dots;kkk++)fa.pop();
            }

            if(num_dots != 0)
            {
                addedge(fa.top(),i);
                tp[i] = fa.top();
            }

            pre_dots =num_dots;
        }

        /*for(int i=1;i<=n;i++)
        {
            cout<<reM[i]<<'>';
            for(int p=head[i];p;p=nxt[p]) cout<<reM[node[p]]<<' ';
            cout<<endl;
        }*/
        dfs(1);

        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            char mark[5];
            scanf("%s",mark);

            if(mark[0] == 'L')
            {
                work(1);
            }
            else if(mark[0] == 'b')
            {
                string tmp;
                cin>>tmp;

                if(deep[(M.find(tmp))->second] == 0) printf("1\n");
                else printf("%d\n",num_son[tp[ (M.find(tmp))->second ]]);
            }
            else if(mark[0] == 'c')
            {
                string tmp1,tmp2;
                cin>>tmp1>>tmp2;
                int Lca = getLca( (M.find(tmp1))->second , (M.find(tmp2))->second );
                if( Lca == (M.find(tmp1))->second || Lca == (M.find(tmp2))->second ) cout<<reM[tp[Lca]];
                else cout<<reM[Lca];
                printf("\n");
            }
        }
    }
    return 0;
}
