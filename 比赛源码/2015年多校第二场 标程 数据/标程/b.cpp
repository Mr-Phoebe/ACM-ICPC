#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
int a, b, x, y, c, d, r;
int main(){
	while(scanf("%d%d%d%d", &a, &b, &x, &y) != EOF){
		assert(1 <= a && a <= 100000000);
		assert(1 <= b && b <= 100000000);
		assert(1 <= x && x <= a);
		assert(1 <= y && y <= b);
		assert((1LL * a * b) > 1);
		if(a > b) swap(a, b), swap(x, y);
		r = (a + 1) / 2;
		c = max(x - 1, a - x);
		d = min(y, b - y + 1);
		if(r < d && x - 1 != a - x)  r = min(c, d);
		if(a == b && (a & 1) && x == y && (x * 2 - 1 == a)) r = a / 2;
		printf("%d\n", r);
	}
	return 0;
}

