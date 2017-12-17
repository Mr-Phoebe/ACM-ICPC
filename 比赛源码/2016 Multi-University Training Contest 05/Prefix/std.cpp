#include <bits/stdc++.h>

using namespace std;

const int N = 100000+5;

int ls[N*40], rs[N*40], cnt[N*40], hd[N], ntot; 

void up(int rt) {
    cnt[rt] = cnt[ls[rt]] + cnt[rs[rt]];
}

void build(int &rt, int l, int r) {
    rt = ntot++;
    cnt[rt] = 0;
    if(l == r)  return ;
    int mid = l+r>>1;
    build(ls[rt], l, mid);
    build(rs[rt], mid+1, r);
    up(rt);
}

void modify(int &rt, int l, int r, int pre, int x, int y) {
    rt = ntot++;
    if(l == r) {
        cnt[rt] = cnt[pre] + y;
        return ;
    }
    int mid = l+r>>1;
    if(x <= mid) {
        modify(ls[rt], l, mid, ls[pre], x, y);
        rs[rt] = rs[pre];
    } else {
        modify(rs[rt], mid+1, r, rs[pre], x, y);
        ls[rt] = ls[pre];
    }
    up(rt);
}

int query(int rt, int l, int r, int L, int R) {
    if(L <= l && R >= r) return cnt[rt];
    int mid = l+r>>1;
    int ret = 0;
    if(L <= mid) ret += query(ls[rt], l, mid, L, R);
    if(R > mid) ret += query(rs[rt], mid+1, r, L, R);
    return ret;
}

string s[N];

int node[N][26];

int tot, n;
int belo[N];

void Insert(string& str) {
    int cur = 0;
    for(int i = 0;i < str.size(); i++) {
        int p = str[i]-'a';
        if(node[cur][p]==0) {
            tot++;
            node[cur][p] = tot;
            memset(node[tot], 0, sizeof(node[tot]));
        }
        cur = node[cur][p];
        belo[cur] = 0;
    }
}

void init() {
    tot = 0;
    memset(node[0], 0, sizeof(node[0]));
    for(int i = 1;i <= n; i++) {
        Insert(s[i]);
    }

    ntot = 0;
    build(hd[0], 1, n);
    for(int i = 1;i <= n; i++) {
        int cur = 0;
        hd[i] = hd[i-1];
        for(int j = 0;j < s[i].size(); j++) {
            int p = s[i][j]-'a';
            cur = node[cur][p];
            if(belo[cur]) {
                modify(hd[i], 1, n, hd[i], belo[cur], -1);
            }
            belo[cur] = i;
        }
        modify(hd[i], 1, n, hd[i], i, s[i].size());
    }
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    while(scanf("%d", &n) == 1) {
        int m = 0;
        for(int i = 1;i <= n; i++) {
            cin>>s[i];
            m += s[i].size();
        }
        init();
        int q, l, r;
        int z = 0;
        scanf("%d", &q);
        while(q--) {
            scanf("%d%d", &l, &r);
            l = (z+l)%n+1; r = (z+r)%n+1;
            if(l > r) swap(l, r);
            z = query(hd[r], 1, n, l, r);
            printf("%d\n", z);
        }
    }
    return 0;
}
