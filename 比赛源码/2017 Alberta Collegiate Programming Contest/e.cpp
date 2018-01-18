#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double n;
	cin >> n;
	double a = log(n)/log(2);
	a /= n;
	a = pow(2,a);
	cout << fixed << setprecision(10) << a << endl;
	return 0;
}