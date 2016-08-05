#include <bits/stdc++.h>

using namespace std;

const int N = 80000+5;
const int MOD = 1e9+7;

int m;
vector<int> vt[N], com[N];
vector<pair<int,int> > prefix[N], suffix[N];
bool mark[N];
int g[N], pre_cnt[N], suf_cnt[N];
int fac[N], ff[N], ans[N];

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

inline void Add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;
}

int a[N], nxt[N], val[N];
int gao(int id) {
    int n = vt[id].size();
    for(int i = 1;i <= n; i++) a[i] = vt[id][i-1];
    int ret = 0;
    for(int i = 1;i <= n; i++) {
        nxt[i] = i; val[i] = a[i];
        int cur = i;
        while(cur) {
            val[cur] = gcd(val[cur], a[i]);
            while(nxt[cur]-1 > 0 && gcd(a[i], val[nxt[cur]-1]) == val[cur]) {
                nxt[cur] = nxt[nxt[cur]-1];
            }
            Add(ret, 1ll*val[cur]*(cur-nxt[cur]+1)%MOD);
            cur = nxt[cur]-1;
        }
    }
    return ret;
}

int solve() {
    int mx = 0;
    for(int i = 0;i < m; i++)
        for(int j = 0;j < vt[i].size(); j++)
            mx = max(mx, vt[i][j]);
    for(int i = 0;i < m; i++) {
        g[i] = 0;
        for(int j = 0;j < vt[i].size(); j++) {
            mx = max(mx, vt[i][j]);
            g[i] = gcd(g[i], vt[i][j]);
            int nxt = j;
            while(nxt+1<vt[i].size() && vt[i][nxt+1]%g[i]==0) nxt++;
            prefix[g[i]].push_back({i,nxt-j+1});
            j = nxt;
        }
        com[g[i]].push_back(i);
        g[i] = 0;
        for(int j = vt[i].size()-1;j >= 0; j--) {
            g[i] = gcd(g[i], vt[i][j]);
            int nxt = j;
            while(nxt-1>=0 && vt[i][nxt-1]%g[i]==0) nxt--;
            suffix[g[i]].push_back({i,j-nxt+1});
            j = nxt;
        }
    }
    for(int i = 0;i < m; i++) mark[i] = 0;
    int ret = 0;
    for(int i = mx;i >= 1; i--) {
        ans[i] = 0;
        int cnt = 0, sum = 0, sum2 = 0;
        for(int j = i;j <= mx; j += i) {
            for(int k = 0;k < com[j].size(); k++) {
                int cur = com[j][k];
                if(!mark[cur]) {
                    cnt++;
                    mark[cur] = 1;
                    sum += vt[cur].size();
                    Add(sum2, 1ll*vt[cur].size()*vt[cur].size()%MOD);
                }
            }
        }
        if(cnt >= 2) {
            for(int j = 0;j <= cnt-2; j++) {
                int tmp = (1ll*sum*sum-sum2)%MOD;
                if(tmp < 0) tmp += MOD;
                tmp = 1ll*tmp*fac[cnt-2]%MOD*ff[cnt-2-j]%MOD*fac[m-j-2+1]%MOD;
                Add(ans[i], tmp);
            }
        }
        for(int j = i;j <= mx; j += i) {
            for(int k = 0;k < prefix[j].size(); k++) if(!mark[prefix[j][k].first]){
                pre_cnt[prefix[j][k].first] += prefix[j][k].second;
            }
            for(int k = 0;k < suffix[j].size(); k++) if(!mark[suffix[j][k].first]){
                suf_cnt[suffix[j][k].first] += suffix[j][k].second;
            }
        }
        int pre_sum = 0, suf_sum = 0, del_sum = 0;
        for(int j = i;j <= mx; j += i) {
            for(int k = 0;k < prefix[j].size(); k++) if(!mark[prefix[j][k].first]){
                int cur = prefix[j][k].first;
                pre_sum += pre_cnt[cur];
                suf_sum += suf_cnt[cur];
                Add(del_sum, 1ll*pre_cnt[cur]*suf_cnt[cur]%MOD);
                mark[cur] = 1;
            }
            for(int k = 0;k < suffix[j].size(); k++) if(!mark[suffix[j][k].first]){
                int cur = suffix[j][k].first;
                pre_sum += pre_cnt[cur];
                suf_sum += suf_cnt[cur];
                Add(del_sum, 1ll*pre_cnt[cur]*suf_cnt[cur]%MOD);
                mark[cur] = 1;
            }
        }
        for(int j = 0;j < cnt; j++) {
            int tmp = 1ll*sum*(pre_sum+suf_sum)%MOD;
            tmp = 1ll*tmp*fac[cnt-1]%MOD*ff[cnt-1-j]%MOD*fac[m-j-2+1]%MOD;
            Add(ans[i], tmp);
        }
        for(int j = 0;j <= cnt; j++) {
            int tmp = (1ll*pre_sum*suf_sum-del_sum)%MOD;
            if(tmp < 0) tmp += MOD;
            tmp = 1ll*tmp*fac[cnt]%MOD*ff[cnt-j]%MOD*fac[m-j-2+1]%MOD;
            Add(ans[i], tmp);
        }
        for(int j = i;j <= mx; j += i) {
            if(j > i) ans[i] -= ans[j];
            if(ans[i] < 0) ans[i] += MOD;
            for(int k = 0;k < com[j].size(); k++)
                mark[com[j][k]] = 0;
            for(int k = 0;k < prefix[j].size(); k++) {
                int cur = prefix[j][k].first;
                mark[cur] = pre_cnt[cur] = suf_cnt[cur] = 0;
            }
            for(int k = 0;k < suffix[j].size(); k++) {
                int cur = suffix[j][k].first;
                mark[cur] = pre_cnt[cur] = suf_cnt[cur] = 0;
            }
        }
        Add(ret, 1ll*ans[i]*i%MOD);
    }
    int add_ret = 0;
    for(int i = 0;i < m; i++) {
        Add(add_ret, gao(i)*1ll*fac[m]%MOD);
    }
    for(int i = 0;i <= mx; i++) {
        com[i].clear();
        prefix[i].clear();
        suffix[i].clear();
    }
    return (ret+add_ret)%MOD;
}

void init(int n) {
    fac[0]=fac[1]=ff[0]=ff[1] = 1;
    for(int i = 2;i <= n; i++) {
        fac[i] = 1ll*fac[i-1]*i%MOD;
        ff[i] = 1ll*(MOD-MOD/i)*ff[MOD%i]%MOD;
    }
    for(int i = 2;i <= n; i++) ff[i] = 1ll*ff[i-1]*ff[i]%MOD;
}

int main() {
    init(N-1);
//    freopen("data1.in", "r", stdin);
//    freopen("data2.out", "w", stdout);
    while(scanf("%d", &m) == 1) {
        int num, x;
        for(int i = 0;i < m; i++) {
            scanf("%d", &num);
            vt[i].clear();
            for(int j = 0;j < num; j++) {
                scanf("%d", &x);
                vt[i].push_back(x);
            }
        }
        printf("%d\n", solve());
    }
    return 0;
}
