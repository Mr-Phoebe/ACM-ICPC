#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val, size;
    node *ch[2], *p;
    bool reverse;
    node (): size(0), reverse(false) {}
    bool d()
    {
        return p->ch[1] == this;
    }
    void rev()
    {
        reverse ^= 1;
    }
    void upd()
    {
        size = ch[0]->size + ch[1]->size + 1;
    }
    void setc(node *c, int d)
    {
        c->p = this;
        ch[d] = c;
    }
    void relax();
} Tnull, *null = &Tnull;

void node::relax()
{
    if(reverse)
    {
        swap(ch[0], ch[1]);
        for(int i = 0; i < 2; ++i)
            if(ch[i])
                ch[i]->rev();
        reverse = false;
    }
}

node *root, mem[130010], *tot;

node *make(int val)
{
    tot->p = null;
    tot->val = val;
    tot->ch[0] = tot->ch[1] = null;
    tot->size = 1;
    tot->reverse = false;
    return tot++;
}

node *build(int l, int r)
{
    if(l > r)
        return null;
    int m = (l+r)>>1;
    node *now = make(m);
    now->setc(build(l, m-1), 0);
    now->setc(build(m+1, r), 1);
    now->upd();
    return now;
}

void rot(node *now)
{
    node *p = now->p;
    p->relax();
    now->relax();
    int d = now->d();
    p->setc(now->ch[!d], d);
    now->p = p->p;
    if(p->p != null)
        p->p->setc(now, p->d());
    now->setc(p, !d);
    p->upd();
    if(now->p == null)
        root = now;
}

void splay(node *now, node *goal = null)
{
    while(now->p != goal)
    {
        if(now->p->p == goal)
            rot(now);
        else
        {
            now->p->d() == now->d() ? rot(now->p) : rot(now);
            rot(now);
        }
    }
    now->upd();
    if(now->p == null)
        root = now;
}

node *find(int rk)
{
    for(node *now = root; ; )
    {
        now->relax();
        int sz = now->ch[0]->size;
        if(rk == sz)
            return now;
        else if(rk > sz)
            rk -= sz+1, now = now->ch[1];
        else
            now = now->ch[0];
    }
}

node *get(int l, int r)
{
    node *_l = find(l-1);
    node *_r = find(r);
    splay(_l);
    splay(_r, _l);
    return _r->ch[0];
}

int ans[130010], anslen;

void inorder(node *now)
{
    if(now == null)
        return ;
    now->relax();
    inorder(now->ch[0]);
    ans[anslen++] = now->val;
    inorder(now->ch[1]);
}

void MAIN()
{
    int n, m;
    scanf("%d%d", &n, &m);
    tot = mem;
    root = build(0, n+1);
    for(int i = 0, l, r; i < m; ++i)
    {
        scanf("%d%d", &l, &r);
        node *now = get(l, r+1);
        now->rev();
    }
    node *now = get(1, n+1);
    anslen = 0;
    inorder(now);
    for(int i = 0; i < n; ++i)
        printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
}

int main()
{
    MAIN();
    return 0;
}
