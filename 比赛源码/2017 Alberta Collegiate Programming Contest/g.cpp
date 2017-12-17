#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string notes[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G","G#"};
	vector<string> v[12];
	int prog[8] = {0,2,4,5,7,9,11,12};
	for(int i=0;i<12;i++){
		for(int j=0;j<8;j++){
			v[i].push_back(notes[(i+prog[j])%12]);
		}
	}
	int n;
	cin >> n;
	string c[n];
	for(int i=0;i<n;i++) cin >> c[i];
	vector<string> res;
	for(int i=0;i<12;i++){
		int flag = 0;
		for(int j=0;j<n;j++){
			int f = 0;
			for(int k=0;k<8;k++){
				if(c[j] == v[i][k]){
					f = 1;
					break;
				}
			}
			if(f == 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0) res.push_back(notes[i]);
	}
	if(res.size() == 0){
		cout << "none";
	}
	else{
		for(int i=0;i<res.size();i++){
			cout << res[i] << " ";
		}
	}
	return 0;
}