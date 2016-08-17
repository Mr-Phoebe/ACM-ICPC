#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char a[105];
stack<int> ans;
int b[105];
int len;

bool vis[105];

bool dfs(int pos)
{
    if(pos >= len)
    {
        int maxpos;
        for(int i=1;i<=100;i++)
        if(vis[i]) maxpos = i;

        for(int i=1;i<=maxpos;i++)
        if(!vis[i]) return false;

        return true;
    }
    bool mark = false;

    if(!vis[b[pos]])
    {
        vis[b[pos]] = true;
        if(dfs(pos+1))
        {
            mark = true;
            ans.push(b[pos]);
        }
        vis[b[pos]] = false;
    }

    if(mark) return true;

    if(pos < len-1 && !vis[ b[pos]*10 + b[pos+1] ])
    {
        vis[ b[pos]*10 + b[pos+1] ] = true;
        if(dfs(pos+2))
        {
            mark = true;
            ans.push(b[pos]*10 + b[pos+1]);
        }
        vis[ b[pos]*10 + b[pos+1] ] = false;
    }
    return mark;
}

int main()
{
    freopen("joke.in","r",stdin);
    freopen("joke.out","w",stdout);

    while(!ans.empty()) ans.pop();

    memset(vis,false,sizeof(vis));

    scanf("%s",a);
    len = strlen(a);

    for(int i=0;i<len;i++)
        b[i] = a[i]-'0';

    dfs(0);

    printf("%d",ans.top());
    ans.pop();

    while(!ans.empty())
    {
        printf(" %d",ans.top());
        ans.pop();
    }
    return 0;
}