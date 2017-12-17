#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double a, n;
	cin >> a >> n;
	double req = 2*sqrt(a*atan(1)*4);
	if(req > n){
		cout << "Need more materials!";
	}
	else{
		cout << "Diablo is happy!";
	}
	return 0;
}