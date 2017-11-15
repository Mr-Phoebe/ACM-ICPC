#include <bits/stdc++.h>

#define int long long
#define MOD 1000000007
using namespace std;
char g[4][4];
map<char, int> cm;
string res = "RRRRGGGGBBBBYYYY";

int hashf(string s){
	int res = 0;
	for(int i=0;i<s.length();i++){
		res  = res*5 + cm[s[i]];
		res %= MOD;
	}
	return res;
}

string s;
map<int, int> dp;

int get(){
	cout << s << endl;
	int hs = hashf(s);
	if(dp[hs] > 0) return dp[hs];
	dp[hs] = -1;
	if(s == res) return 0;
	int ans = 1e9;
	for(int i=0;i<2;i++){
		for(int j=0;j<4;j++){
			if(ans < 2) break;
			int dir = i;
			if(i == 0) dir = -1;
			for(int k=0;k<3;k++){
				swap(s[k*4 + j], s[(k+dir)*4 + j]);
			}
			if(dp[hashf(s)] == -1) continue;
			else ans = min(ans, 1 + get());
			int antdir = -dir;
			for(int k=0;k<4;k++){
				temp[k*4 + j] = s[((k+antdir+4)%4)*4 + j];
			}
			s = temp;
		}
	}
	//rows
	for(int i=0;i<2;i++){
		for(int j=0;j<4;j++){
			if(ans < 2) break;
			string temp = s;
			int dir = i;
			if(i == 0) dir = -1;
			for(int k=0;k<4;k++){
				temp[j*4 + k] = s[j*4 + ((k+dir+4)%4)];
			}
			s = temp;
			//cout << temp << endl;
			//return 0;
			if(dp[hashf(temp)] == -1) continue;
			else ans = min(ans, 1 + get());
			int antdir = -dir;
			for(int k=0;k<4;k++){
				temp[j*4 + k] = s[j*4 + ((k+antdir+4)%4)];
			}
			s = temp;
		}
	}
	dp[hs] = ans;
	return ans;
}




signed main(){
	s= "";
	
	for(int i=0;i<4;i++) for(int j=0;j<4;j++){
		cin >> g[i][j];
		s += g[i][j];
	}
	cm['R'] = 1;
	cm['Y'] = 2;
	cm['B'] = 3;
	cm['G'] = 0;
	
	cout << get();
	
	return 0;
}
