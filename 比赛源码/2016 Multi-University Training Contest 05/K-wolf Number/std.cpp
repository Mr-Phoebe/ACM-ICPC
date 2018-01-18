#include <bits/stdc++.h>
using LL = long long ;

std::vector<int> L,R;
int K;
std::map<std::vector<int>,LL> dp[18];

LL calc(int at,std::vector<int> mask,bool samel,bool samer) {
    if (at == -1) {
        return 1;
    }
    bool save = !(samel | samer);
    if (save && dp[at].find(mask) != dp[at].end()) {
        return dp[at][mask];
    }

    LL ret = 0;
    for (int c = 0; c < 10; ++ c) {
        if (samel && c < L[at]) continue;
        if (samer && c > R[at]) continue;
        if (std::find(mask.begin(),mask.end(),c) != mask.end()) continue;
        auto n_mask = mask;
        if (c != 0 || !mask.empty()) {
            n_mask.push_back(c);
            if (n_mask.size() == K) {
                n_mask.erase(n_mask.begin());
            }
        }
        ret += calc(at - 1,n_mask,samel && c == L[at],samer && c == R[at]);
    }

    if (save) {
        dp[at][mask] = ret;
    }
    return ret;
}

LL brute(LL l,LL r,int K) {
    LL ret = 0;
    for (LL x = l; x <= r; ++ x) {
        std::vector<int> vec;
        for (LL t = x; t; t = t / 10) {
            vec.emplace_back(t % 10);
        }
        bool flag = true;
        for (int i = 0; i < (int)vec.size(); ++ i) {
            int mask = 0;
            for (int j = 0; i + j < vec.size() && j < K; ++ j) {
                int tmp = vec[i + j];
                if (mask >> tmp & 1) {
                    flag = false; break;
                }
                mask |= 1 << tmp;
            }
        }
        ret += flag;
    }
    return ret;
}

int main() {
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    LL l,r;
    while (scanf("%I64d%I64d%d",&l,&r,&K) == 3) {
        assert(1 <= l && l <= r && r <= (LL)1e18 && K >= 2 && K <= 5);
        auto decompose = [](LL x) {
            std::vector<int> ret;
            while (x) {
                ret.push_back(x % 10);
                x /= 10;
            }
            return ret;
        };
        L = decompose(l);
        R = decompose(r);
        L.resize((int)R.size(),0);
        for (int i = 0; i < 18; ++ i) {
            dp[i].clear();
        }
        LL result = calc((int)R.size() - 1,std::vector<int>(),true,true);
        printf("%I64d\n",result);
        //assert(result == brute(l,r,K));
    }
    fprintf(stderr,"time = %.6f\n",clock() * 1. / CLOCKS_PER_SEC);
}
