#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	map<string, vector<int> > m;
	int n = s.length();
	for(int i=0;i<n;i++){
		string temp = "";
		for(int j=i;j<n;j++){
			temp += s[j];
			m[temp].push_back(i);
		}
	}
	int res = n;
	for(map<string, vector<int> >::iterator it = m.begin();it!=m.end();it++){
		int cur = (it->first).length();
		vector<int> v = it->second;
		int u = 0;
		int last = -100;
		for(size_t i=0;i<v.size();i++){
			if(v[i] - last >= cur){
				last = v[i];
				u++;
			}
		}
		res = min(res, n - cur*u + u + cur);
	}
	cout << res << endl;
	return 0;
}
