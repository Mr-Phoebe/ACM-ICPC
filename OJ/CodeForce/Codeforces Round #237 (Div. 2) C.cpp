#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100005;

int k, n, d[N];
vector <int> len[N];
vector < pair <int, int> > edge;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; i ++) len[i].clear();
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &d[i]);
        len[d[i]].push_back(i);
    }
    if (len[0].size() != 1) {
        printf("-1\n");
        return 0;
    }
    int maxLen = n;
    for (; len[maxLen].size() == 0; maxLen --);
    for (int i = 0; i <= maxLen; i ++) {
        if (len[i].size() == 0) {
            printf("-1\n");
            return 0;
        }
    }
    edge.clear();
    for (int i = 1; i <= maxLen; i ++) {
        int cnt1 = (int)len[i - 1].size();
        int cnt2 = (int)len[i].size();
        int cnt = cnt2 / cnt1 + (cnt2 % cnt1 != 0);
        if (cnt + (i - 1 != 0) > k) {
            printf("-1\n");
            return 0;
        }
        for (int id1 = 0, id2 = 0; id1 < cnt1 && id2 < cnt2; id1 ++) {
            for (; id2 < (id1 + 1) * cnt && id2 < cnt2; id2 ++) {
                edge.push_back(make_pair(len[i - 1][id1], len[i][id2]));
            }
        }
    }
    int cnt = (int)edge.size();
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i ++) {
        printf("%d %d\n", edge[i].first, edge[i].second);
    }
    return 0;
}