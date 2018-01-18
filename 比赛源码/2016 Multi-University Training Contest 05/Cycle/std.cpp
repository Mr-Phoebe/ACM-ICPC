#include <bits/stdc++.h>

using namespace std;
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)

const int N = 10000+5;

int wa[N<<1], wb[N<<1], wc[N<<1], wv[N<<1];
bool cmp(int *r, int a, int b, int l) {
    return r[a]==r[b] && r[a+l]==r[b+l];
}
void da(int *r, int *sa, int n, int m) {
    int *x = wa, *y = wb;
    for(int i = 0;i < m; i++) wc[i] = 0;
    for(int i = 0;i < n; i++) wc[x[i]=r[i]]++;
    for(int i = 1;i < m; i++) wc[i] += wc[i-1];
    for(int i = n-1;i >= 0; i--) sa[--wc[x[i]]] = i;
    for(int j = 1,p = 1;p < n; j <<= 1, m = p) {
        p = 0;
        for(int i = n-j;i < n; i++) y[p++] = i;
        for(int i = 0;i < n; i++) if(sa[i]>=j) y[p++] = sa[i]-j;
        for(int i = 0;i < n; i++) wv[i] = x[y[i]];
        for(int i = 0;i < m; i++) wc[i] = 0;
        for(int i = 0;i < n; i++) wc[wv[i]]++;
        for(int i = 1;i < m; i++) wc[i] += wc[i-1];
        for(int i = n-1;i >= 0; i--) sa[--wc[wv[i]]] = y[i];
        int *t = x; x = y; y = t;
        p = 1; x[sa[0]] = 0;
        for(int i = 1;i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
    }
}
void calheight(int *r, int *sa, int *rk, int *height, int n) {
    for(int i = 1;i <= n; i++) rk[sa[i]] = i;
    int k = 0;
    for(int i = 0;i < n; height[rk[i++]] = k) {
        if(k) k--;
        for(int j = sa[rk[i]-1]; r[i+k]==r[j+k]; k++) ;
    }
}
int Log[N<<1], rq[N<<1][20];

void build_rmq(int *a, int n) {
    for(int i = 1;i <= n; i++)  rq[i][0] = a[i];
    for(int j = 1;j < 20; j++) {
        for(int i = 1;i+(1<<j)-1 <= n; i++)
            rq[i][j] = min(rq[i][j-1], rq[i+(1<<j-1)][j-1]);
    }
    int cr = 0;
    for(int i = 1;i <= n; i++) {
        while((1<<cr+1) <= i) cr++;
        Log[i] = cr;
    }
}
int query_rmq(int l, int r) {
    int k = Log[r-l+1];
    return min(rq[l][k], rq[r-(1<<k)+1][k]);
}

int a[N<<1], sa[N<<1], rk[N<<1], height[N<<1];

char s1[N], s2[N];
bitset<10000> ans, bs[N], pre[N];
pair<int,int> vt[N];

void solve() {
    int n = strlen(s1);
    int tot = 0;
    for(int i = 0;i < n; i++) a[tot++] = s1[i]-'a'+1;
    a[tot++] = 27;
    for(int i = 0;i < n; i++) a[tot++] = s2[i]-'a'+1;
    a[tot++] = 0;
    da(a, sa, tot, 28);
    calheight(a, sa, rk, height, tot-1);
    build_rmq(height, tot-1);

    for(int i = 0;i < n; i++) {
        int l = rk[n+1+i], r = rk[0];
        if(l > r) swap(l, r);
        int len = query_rmq(l+1, r);
        vt[i] = {-len, i};
    }
    sort(vt, vt+n);
    bitset<10000> tmp;
    int cr = 0;
    for(int i = n-1;i >= 0; i--) {
        while(cr<n && -vt[cr].first >= i+1) {
            tmp[vt[cr].second] = 1;
            cr++;
        }
        bs[i] = tmp;
    }
    ans.reset();
    for(int i = 0;i < n; i++) {
        int l = rk[i], r = rk[n+1];
        if(l > r) swap(l, r);
        int len = query_rmq(l+1, r);
        if(len > 0) {
            if(i > 0)
                ans |= (pre[i+len-1]^pre[i-1])&(bs[i-1]<<(i-1));
            else
                ans |= pre[i+len-1];
        }
    }
    for(int i = 0;i < n; i++) {
        if(ans.test(i)) printf("1");
        else    printf("0");
    }
    puts("");
}

void init() {
    pre[0][0] = 1;
    for(int i = 1;i <= 10000; i++) {
        pre[i] = pre[i-1];
        pre[i][i] = 1;
    }
}

int main() {
    init();
        //freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    while(scanf("%s%s", s1, s2) == 2) {
        solve();
    }
 //   showtime;
    return 0;
}
