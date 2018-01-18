#include <bits/stdc++.h>
using LL = long long ;
#define ALL(v) (v).begin(),(v).end()
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)

struct Node {
    int lc,rc;
    int cnt;

    Node() {
        lc = rc = cnt = 0;
    }
};

const int N = 100000 + 5;
const int D = N * 18;
Node node[D];
int tot;
std::vector<int> edges[N];
int tree[N];
int A[N];
int val[N][2];
int n;


std::vector<int> vec[N];

LL b_dfs(int u) {
    LL ret = 0;
    vec[u].clear();
    vec[u].emplace_back(A[u]);
    for (int v : edges[u]) {
        ret += b_dfs(v);
        vec[u].insert(vec[u].end(),vec[v].begin(),vec[v].end());
    }
    std::sort(ALL(vec[u]));
    return ret + vec[u][(int)(vec[u].size() + 1) / 2 - 1];
}

LL brute() {
    LL ret = 0;
    for (int u = 1; u <= n; ++ u) {
        int tmp = A[u];
        A[u] = 100000;
        ret = std::max(ret,b_dfs(1));
        A[u] = tmp;
    }
    return ret;
}

struct Fenwick {
    LL C[N];

    void modify(int p,int dt) {
        for (int i = p; i > 0; i -= i & -i) C[i] += dt;
    }
    LL query(int p) {
        LL ret = 0;
        for (int i = p; i < N; i += i & -i) ret += C[i];
        return ret;
    }
} bit;

int build(int p,int l,int r) {
    assert(tot < D);
    int z = tot ++;
    node[z].cnt = 1;
    node[z].lc = node[z].rc = 0;
    if (l == r) return z;
    int mid = l + r >> 1;
    if (p <= mid) node[z].lc = build(p,l,mid);
    else node[z].rc = build(p,mid + 1,r);
    return z;
}

int merge(int a,int b,int l,int r) {
    if (a == 0) return b;
    if (b == 0) return a;
    node[a].cnt += node[b].cnt;
    if (l == r) {
        node[a].lc = node[a].rc = 0;
        return a;
    }
    int mid = l + r >> 1;
    node[a].lc = merge(node[a].lc,node[b].lc,l,mid);
    node[a].rc = merge(node[a].rc,node[b].rc,mid + 1,r);
    return a;
}

int query(int o,int K,int l,int r) {
    if (node[o].cnt < K) return 100000;
    if (l == r) return l;
    int mid = l + r >> 1;
    if (node[node[o].lc].cnt >= K) return query(node[o].lc,K,l,mid);
    return query(node[o].rc,K - node[node[o].lc].cnt,mid + 1,r);
}

void dfs(int u) {
    tree[u] = build(A[u],1,100000);
    for (int v : edges[u]) {
        dfs(v);
        tree[u] = merge(tree[u],tree[v],1,100000);
    }
    val[u][0] = query(tree[u],node[tree[u]].cnt + 1 >> 1,1,100000);
    val[u][1] = query(tree[u],(node[tree[u]].cnt + 1 >> 1) + 1,1,100000);
}

LL ffs(int u) {
    bit.modify(val[u][0],val[u][1] - val[u][0]);
    LL ret = bit.query(val[u][0]);
    for (int v : edges[u]) {
        ret = std::max(ret,ffs(v));
    }
    bit.modify(val[u][0],val[u][0] - val[u][1]);
    return ret;
}

int main() {
    int __size__ = 64 << 20;
    char *__p__ = (char*)malloc(__size__) + __size__;
    __asm__("movl %0, %%esp\n"::"r"(__p__));

    int ca = 0;
    while (scanf("%d",&n) == 1) {
        //fprintf(stderr,"case = %d\n",++ca);
        assert(1 <= n && n <= 100000);
        for (int i = 1; i <= n; ++ i) {
            scanf("%d",A + i);
            assert(1 <= A[i] && A[i] <= 100000);
        }
        for (int i = 1; i <= n; ++ i) {
            edges[i].clear();
        }
        for (int i = 2; i <= n; ++ i) {
            int x;
            scanf("%d",&x);
            assert(x >= 1 && x < i);
            edges[x].emplace_back(i);
        }
        tot = 1;
        dfs(1);
        LL sum = 0;
        for (int i = 1; i <= n; ++ i) {
            sum += val[i][0];
        }
        LL result = sum + ffs(1);
        printf("%I64d\n",result);
        /*
        fprintf(stderr,"delta = %I64d\n",result - sum);
        if (n <= 1000) {
            fprintf(stderr,"bruting\n");
            assert(result == brute());
        }
        */
    }
    showtime;
}
