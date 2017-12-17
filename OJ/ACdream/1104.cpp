#include <bits/stdc++.h>

using namespace std;

const int base = 31, mod = 1e9+7;
long long mul[150010];


struct node
{
    int val, size;
    long long lhash, rhash;
    node *p, *ch[2];
    node (): val(0), size(0), lhash(0), rhash(0) {}
    bool d()
    {
        return p->ch[1] == this;
    }
    void setc(node *c, int d)
    {
        c->p = this;
        ch[d] = c;
    }
    void upd()
    {
        size = ch[0]->size + ch[1]->size + 1;
        lhash = (ch[0]->lhash*mul[ch[1]->size+1] %mod + val*mul[ch[1]->size] %mod + ch[1]->lhash) %mod;
        rhash = (ch[1]->rhash*mul[ch[0]->size+1] %mod + val*mul[ch[0]->size] %mod + ch[0]->rhash) %mod;
        //  lhash = (val + ch[0]->lhash * base) %mod;
        //  rhash = (val + ch[1]->rhash * base) %mod;
    }
} Tnull, *null = &Tnull;

node mem[150010], *tot, *root;

void rot(node *now)
{
    node *p = now->p;
    int d = now->d();
    p->setc(now->ch[!d], d);
    now->p = p->p;
    if(p->p != null)
        p->p->setc(now, p->d());
    else
        root = now;
    p->upd();
    now->setc(p, !d);
}

void splay(node *now, node *goal = null)
{
    while(now->p != goal)
    {
        if(now->p->p == goal)
            rot(now);
        else
        {
            now->d() == now->p->d() ? rot(now->p) : rot(now);
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
        int sz = now->ch[0]->size;
        if(sz == rk)
            return now;
        else if(rk > sz)
            rk -= sz+1, now = now->ch[1];
        else
            now = now->ch[0];
    }
}

node *make(int val)
{
    tot->val = val;
    tot->p = null;
    tot->ch[0] = tot->ch[1] = null;
    tot->lhash = tot->rhash = val;
    tot->size = 1;
    return tot++;
}

void insert(int pos, int val)
{
    node *pred = find(pos), *succ = find(pos+1);
    splay(succ);
    splay(pred, succ);
    pred->setc(make(val), 1);
    pred->upd();
    succ->upd();
}

void del(int pos)
{
    node *pred = find(pos-1), *succ = find(pos+1);
    splay(succ);
    splay(pred, succ);
    pred->ch[1] = null;
    pred->upd();
    succ->upd();
}

void update(int pos, int val)
{
    node *now = find(pos);
    now->val = now->lhash = now->rhash = val;
    splay(now);
}

int query(int pos, int nowlen)
{
    int l = 0, r = min(pos-1, nowlen-pos);
    int ans;
    while(l <= r)
    {
        int m = (l+r)>>1;
        node *tmp = find(pos+m+1);
        splay(tmp);
        node *tmpp = find(pos-m-1);
        splay(tmpp, tmp);
        node *now = find(pos);
        splay(now, tmpp);
        if(now->lhash == now->rhash)
            ans = m, l = m+1;
        else
            r = m-1;
    }
    return ans;
}

char str[150010];

node* build(int l, int r)
{
    if(l > r)
        return null;
    int m = (l+r)>>1;
    node *now = make(str[m] - 'a' + 1);
    now->setc(build(l, m-1), 0);
    now->setc(build(m+1, r), 1);
    now->upd();
    return now;
}


int main()
{
    mul[0] = 1;
    for(int i = 1; i <= 150000; ++i)
        mul[i] = mul[i-1] * base %mod;
    tot = mem;
    root = make(0);
    root->setc(make(0), 1);
    scanf("%s", str);
    int len = strlen(str);
    root->ch[1]->setc(build(0, len-1), 0);
    root->ch[1]->upd();
    int m;
    scanf("%d", &m);
    char op[10];
    while(m--)
    {
        int a;
        char s[2];
        scanf("%s%d", op, &a);
        if(op[0] == 'I')
        {
            scanf("%s", s);
            insert(a, s[0]-'a'+1);
            ++len;
        }
        else if(op[0] == 'D')
            del(a), --len;
        else if(op[0] == 'U')
        {
            scanf("%s", s);
            update(a, s[0]-'a'+1);
        }
        else
        {
            printf("%d\n", 1+2*query(a, len));
        }
    }
    return 0;
}

