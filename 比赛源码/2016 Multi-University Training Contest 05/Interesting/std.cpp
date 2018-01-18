#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int N = 1000000+5;
char s[N], str[N<<1];
int p[N<<1];
int odd[N], even[N], cntL[N], cntR[N];
int cnt1[N], cnt2[N], val1[N], val2[N];

void gao() {
    str[0] = '$';
    str[1] = '#';
    int n = strlen(s);
    int len = 2;
    for(int i = 0;i < n; i++) {
        str[len++] = s[i];
        str[len++] = '#';
    }
    str[len] = 0;
    p[0] = 1;
    int id = 0, mx = 1;
    for(int i = 1;i < len; i++) {
        if(mx > i) {
            p[i] = min(p[2*id-i], mx-i);
        } else {
            p[i] = 1;
        }
        while(str[i-p[i]] == str[i+p[i]]) p[i]++;
        if(i+p[i] > mx) {
            mx = i+p[i];
            id = i;
        }
    }
}

inline void Add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;
    if(x < 0) x += MOD;
}

int solve() {
    gao();
    int n = strlen(s);
    for(int i = 0;i < n; i++) {
        odd[i] = p[i*2+2]-1;
        even[i] = i ? p[i*2+1]-1 : 0;
    }
    for(int i = 0;i < n; i++) {
        cnt1[i] = cnt2[i] = 0;
        val1[i] = val2[i] = 0;
    }
    for(int i = 0;i < n; i++) {
        cnt1[i]++; cnt1[i+odd[i]/2+1]--;
        Add(val1[i], 2*(i+1));
        Add(val2[i+odd[i]/2+1], MOD-2*(i+1));

        if(!even[i]) continue;
        cnt2[i]++; cnt2[i+even[i]/2]--;
        Add(val2[i], 2*(i+1));
        Add(val2[i+even[i]/2], MOD-2*(i+1));
        
    }
    for(int i = 1;i < n; i++) {
        cnt1[i] += cnt1[i-1];
        Add(val1[i], val1[i-1]);
        cnt2[i] += cnt2[i-1];
        Add(val2[i], val2[i-1]);
    }
    for(int i = 0;i < n; i++) {
        cntL[i] = (val1[i]-1ll*(i+1)*cnt1[i]%MOD + val2[i]-1ll*(i+1)*cnt2[i]%MOD-cnt2[i])%MOD;
        Add(cntL[i], 0);
    }

    for(int i = 0;i < n; i++) {
        cnt1[i] = cnt2[i] = 0;
        val1[i] = val2[i] = 0;
    }
    for(int i = 0;i < n; i++) {
        cnt1[i-odd[i]/2]++; cnt1[i+1]--;
        Add(val1[i-odd[i]/2], 2*(i+1));
        Add(val1[i+1], MOD-2*(i+1));

        if(!even[i]) continue;
        cnt2[i-even[i]/2] ++; cnt2[i] --;
        Add(val2[i-even[i]/2], 2*(i+1));
        Add(val2[i], MOD-2*(i+1));
    }
    for(int i = 1;i < n; i++) {
        cnt1[i] += cnt1[i-1];
        Add(val1[i], val1[i-1]);
        cnt2[i] += cnt2[i-1];
        Add(val2[i], val2[i-1]);
    }
    for(int i = 0;i < n; i++) {
        cntR[i] = (val1[i]-1ll*(i+1)*cnt1[i]%MOD + val2[i]-1ll*(i+1)*cnt2[i]%MOD-cnt2[i])%MOD;
        Add(cntR[i], 0);
    }
    int ans = 0;
    for(int i = 0;i+1 < n; i++)
        Add(ans, 1ll*cntL[i]*cntR[i+1]%MOD);
    return ans;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    while(scanf("%s", s) == 1) {
        printf("%d\n", solve());
    }
    return 0;
}
