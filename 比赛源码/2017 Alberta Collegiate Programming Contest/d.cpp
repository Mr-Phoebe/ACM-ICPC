#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	n *= 2;
	int v[n];
	for(int i=0;i<n;i++) v[i] = 0;
	int a[2][n];
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++) cin >> a[i][j];
	}
	int p = 0;
	int c[2];
	c[0] = 0,c[1] = 0;
	int count[2];
	count[0] = 0, count[1] = 0;
	int flag = 0;
	while( count[0] + count[1] != n){
		//cout << p << " " << c[p] << a[p][c[p]] << endl;
		if(flag == 1){
			flag = 0;
			int last = a[1^p][c[1^p]-1];
			v[last] = 1;
			if(last&1) last -= 1;
			else last += 1;
			v[last] = 1;
			count[p] += 2;
			flag = 0;
		}
		int aa = -1;
		while(1){
			if(count[0] + count[1] == n) break;
			int next = a[p][c[p]];
				c[p]++;
			if(v[next] == 1){
				continue;
			}
			v[next] = 1;
			int partner = next;
			if(partner&1) partner -= 1;
			else partner += 1;
			if(v[partner]){
				count[p] += 2;
				continue;
			}
			aa = next;
			break;
		}
		int bb = -1;
		while(1){
			if(count[0] + count[1] == n) break;
			int next = a[p][c[p]];
			c[p]++;
			if(v[next] == 1) continue;
			v[next] = 1;
			bb = next;
			break;
		}
		int partner = bb;
		if(bb&1) partner -= 1;
		else partner += 1;
		if(aa == partner){
			count[p] += 2;
			continue;
		}
		if(v[partner] == 1){
			flag = 1;
		}
		p ^= 1;
	}
	if(count[0] == count[1]) cout << "-1";
	else if(count[0] > count[1]) cout << "0";
	else cout << "1";
	return 0;
}