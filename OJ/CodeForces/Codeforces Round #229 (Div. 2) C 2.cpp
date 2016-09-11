#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <ctime>
#include <functional>
#include <bitset>

#define pb push_back
#define mk make_pair
#define sqr(N) ((N)*(N))
#define F first
#define S second
#define maxn 1010101

using namespace std;                         

typedef long long ll;

int i, n, m, k, cnt1[maxn], cnt2[maxn], how[maxn], ans[maxn];

char s[maxn];

int main(){
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
  scanf("%d %d %d", &n, &k, &m);
  scanf("%s", s + 1);
  for(i = 1; i <= n; i++)
  	{
    s[i] -= 48;
    how[i] = 1;
    cnt1[i] = cnt2[i] = s[i];
    cnt1[i] += cnt1[i - 1];
    if(i - k > 0) cnt2[i] += cnt2[i - k], how[i] += how[i - k];
    ans[i] = how[i] - cnt2[i] + cnt1[i] - cnt2[i];
  }
  for(i = 1; i <= m; i++){
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", ans[r] - ans[l - 1]);
  }
  return 0;
}        
