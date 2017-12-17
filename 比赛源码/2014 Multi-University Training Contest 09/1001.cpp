//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 5010

int n, v[N], a[N];
vector<pii> que;
int dp[N];

void check(int &x, int y) {
    if (x == -1 || x > y) x = y;
}
int init() {
    que.clear();
    if (n == 1) return 1;
    int l = 0 , r = n - 1, l_num = 1, r_num = 1; 
    LL  l_val = v[0], r_val = v[n - 1];
    while (l < r) {
        if (l_val < r_val) {
            if (l + 1 == r) return l_num + r_num;
            l_val += v[++l];
            l_num ++;
        }
        else if (l_val > r_val) {
            if (l + 1 == r) return l_num + r_num;
            r_val += v[--r];
            r_num ++;
        }
        else {
            que.push_back(mp(l_num, r_num));
            if (l + 1 == r) return 0;
            if (l + 2 == r) return 1;
            l_num = r_num = 1;
            l_val = v[++l];
            r_val = v[--r];
        }
    }
    return 0;
}

int main() {
    while (scanf("%d", &n), n > 0){
    	Rep(i, n) scanf("%d", &v[i]);
    	Rep(i, n) scanf("%d", &a[i + 1]);
    	int mid_element = init();
    	int nn = que.size();
    	memset(dp, -1, sizeof dp);
    	dp[0] = 0;
    	for (int i = 0; i<nn; i++) {
        	int num1 = 0, num2 = 0;
        	for (int j = i; j<nn; j++) {
            		num1 += que[j].X, num2 += que[j].Y;
            		check(dp[j + 1], dp[i] + a[num1] + a[num2]);
        	}
    	}
    	int ans = -1;
    	for (int i = nn; i>=0; i--) {
        	check(ans, dp[i] + a[mid_element]);
        	if (i) mid_element += que[i - 1].X + que[i - 1].Y;
    	}
    	printf("%d\n", ans);
    }
    return 0;
}
