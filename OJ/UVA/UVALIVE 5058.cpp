#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val, size;
    node *ch[2];
    node (): val(0), size(0) {}
    void upd()
    {
        size = ch[0]->size + ch[1]->size + 1;
    }
    void setc(node *c, int d)
    {
        ch[d] = c;
    }
} Tnull, *null = &Tnull;

node *root, mem[1010], *tot;

node *make(int val)
{
    tot->val = val;
    tot->size = 1;
    tot->ch[0] = tot->ch[1] = null;
    return tot++;
}

void insert(node *now, int val)
{
    if(now->val > val)
    {
        if(now->ch[0] == null)
            now->setc(make(val), 0);
        else
            insert(now->ch[0], val);
    }
    else
    {
        if(now->ch[1] == null)
            now->setc(make(val), 1);
        else
            insert(now->ch[1], val);
    }
    now->upd();
}

long long c[1010][1010];
const int mod = 1e6+3;

void init()
{
    c[0][0] = 1;
    for(int i = 1; i <= 1000; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; ++j)
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) %mod;
    }
}

long long dfs(node *now)
{
    if(now == null)
        return 1;
    return dfs(now->ch[0]) * dfs(now->ch[1]) %mod * c[now->size-1][now->ch[0]->size] %mod;
}

void inorder(node *now)
{
    if(now == null)
        return ;
    inorder(now->ch[0]);
    printf("%d\n", now->val);
    inorder(now->ch[1]);
}

void inorder()
{
    inorder(root);
}


int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        tot = mem;
        for(int i = 0, tmp; i < n; ++i)
        {
            scanf("%d", &tmp);
            if(i == 0)
                root = make(tmp);
            else
                insert(root, tmp);
        }
        printf("%lld\n", dfs(root) * c[m][n] %mod);
    }
    return 0;
}
