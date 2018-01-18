#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <bitset>
#include <vector>
#include <string>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define REP(i, x, y)  for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y)  for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y)  for(int i = (int)x; i >= (int)y; i --)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int, int> PII;
const	int N = 100005;
const	int inf = 1e9;
const	ll Inf = 1e16;
const	int P = (int)1e9 + 7;

int n, x[N], y[N], app[N << 3], m;

void Main(){
	scanf("%d%d", &n, &m);
	memset(app, 0, sizeof app);
	REP(i, 1, n) scanf("%d%d", x + i, y + i);
	REP(i, 1, n) REP(j, i + 1, n){
		int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		if(!app[dist]){
			app[dist] = 1;
		}else{
			puts("YES");
			goto find;
		}
	}
	puts("NO");
	find:;
}

int main(){
	int T = 0;
	scanf("%d", &T);
	while(T --) Main();
	return 0;
}
