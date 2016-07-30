#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int maxn=110000;

set<int> chat,st;
bool vis[maxn];
int id[maxn];
char op[maxn];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        getchar();
        scanf("%c%d",op+i,id+i);
    }
    for(int i=0;i<m;i++)
    {
        if(op[i]=='-')
        {
            if(vis[id[i]]==false)
                chat.insert(id[i]);
        }
        vis[id[i]]=true;
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<m;i++)
    {
        if(op[i]=='+')
        {
            if(chat.size()>0) vis[id[i]]=true;
            else st.insert(id[i]);
            chat.insert(id[i]);
        }
        else if(op[i]=='-')
        {
            if(chat.size()>1) vis[id[i]]=true;
            else st.insert(id[i]);
            chat.erase(id[i]);
        }
    }
    if(st.size()>1)
    {
        set<int>::iterator it;
        for(it=st.begin();it!=st.end();it++)
        {
            vis[*it]=true;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(vis[i]) cnt++;
    printf("%d\n",n-cnt);
    for(int i=1;i<=n;i++)
        if(!vis[i]) printf("%d ",i);
    putchar(10);
    return 0;
}
