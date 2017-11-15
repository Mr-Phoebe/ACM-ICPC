#include <bits/stdc++.h>

using namespace std;

struct thing{
	int v, w;
	thing(int _v, int _w): v(_v), w(_w){};
};

int f[5000];
int a[5000][4];
vector<thing> remaining;

int main(){
	int n;
	int hold=0, lost=0, remain=0;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i][0]>> a[i][1]>> a[i][2]>> a[i][3];
		if (a[i][1] + a[i][3] <= a[i][2]) {
			lost += a[i][0];
		}
		else if (a[i][2] + a[i][3] < a[i][1]) {
			hold += a[i][0];
		}
		else {
			remain += a[i][0];
			remaining.push_back(thing( (a[i][3] - a[i][1] + a[i][2])/2+1, a[i][0]));
			//cout << remaining.back().w << " " << remaining.back().v << endl;
		}
	}
	if (hold + remain <= lost) cout << "impossible" << endl;
	else if (lost +remain < hold) cout << 0 << endl;
	else {
		//cout << remain << endl;
		for (int i=0; i<=remain; i++) {
			f[i] = 1e9+1;
		}
		f[0] = 0;
		//cout << remaining.size() << endl;
		for (int i=0; i<remaining.size(); i++) {
			for (int j=remain; j>=0; j--) {
				if (j-remaining[i].w>=0) 
					f[j] = min(f[j], f[j-remaining[i].w] + remaining[i].v);
			}
		}
		int ans=1e9+1;
		//cout << (remain - hold + lost) / 2 + 1 << endl;
		for (int i=(remain - hold + lost) / 2 + 1; i<=remain; i++) {
			if (f[i]<ans) ans = f[i];
		}
		cout << ans << endl;
	}
}
	
