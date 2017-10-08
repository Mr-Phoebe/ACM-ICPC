#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int s,d;
	cin >> d >> s;
	double l = 0, h = 10000000;
	double res;
	for(int i=0;i<2000000;i++){
		double a = (l+h)/2;
		res = cosh((0.5*d)/a);
		res *= a;
		res -= a;
		if(res < s) h = a;
		else l = a;
	}
//	cout << res << " " << l << " " << h << endl;
	res = 2*l;
	res *= sinh((0.5*d)/l);
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}
