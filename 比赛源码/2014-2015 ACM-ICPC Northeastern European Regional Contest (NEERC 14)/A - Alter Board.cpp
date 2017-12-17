//By LH
#pragma warning(disable:4996)
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int n, m, ans;

int main()
{
    freopen("alter.in","r",stdin);
    freopen("alter.out","w",stdout);
    scanf("%d%d", &n, &m);
    ans = m/2+n/2;
    printf("%d\n", ans);
    for (int i = 1; i <= m/2; i++) printf("%d %d %d %d\n", 1, 2*i, n, 2*i);
    for (int i = 1; i <= n/2; i++) printf("%d %d %d %d\n", 2*i, 1, 2*i, m);
    return 0;
}