#include <bits/stdc++.h>

using namespace std;

struct car{
	int x;
	double len, pos;
};
int n,m;
car acm;
vector<car> lines[101];
bool visit[101][200];

bool dfs(car temp) {
	if (temp.x == n-1) return true;
	int l1=temp.x, l2=l1+1;
	int i1=0;
	while (lines[l1][i1].pos+lines[l1][i1].len <= temp.pos) i1++;
	i1--;
	visit[l1][i1] = false;
	for (int i=0; i<lines[l2].size()-1; i++) {
		if (visit[l2][i]) {
			double cur_low = lines[l1][i1].pos+lines[l1][i1].len;
			double cur_up = lines[l1][i1+1].pos;
			double next_low = lines[l2][i].pos+lines[l2][i].len;
			double next_up = lines[l2][i+1].pos;
			if (!(cur_low >= next_up || cur_up <= next_low)) {
				double dis = min(cur_up, next_up) - max(cur_low, next_low);
				if (dis >= temp.len) {
					car nextc;
					nextc.x = temp.x+1;
					nextc.pos = max(cur_low, next_low);
					nextc.len = temp.len;
					if (dfs(nextc)) return true;
				}
			}
		}
	}
	if (l1 != 0){
		l2 = l1 - 1;
		for (int i=0; i<lines[l2].size()-1; i++) {
			if (visit[l2][i]) {
				double cur_low = lines[l1][i1].pos+lines[l1][i1].len;
				double cur_up = lines[l1][i1+1].pos;
				double next_low = lines[l2][i].pos+lines[l2][i].len;
				double next_up = lines[l2][i+1].pos;
				if (!(cur_low >= next_up || cur_up <= next_low)) {
					double dis = min(cur_up, next_up) - max(cur_low, next_low);
					if (dis >= temp.len) {
						car nextc;
						nextc.x = temp.x-1;
						nextc.pos = max(cur_low, next_low);
						nextc.len = temp.len;
						if (dfs(nextc)) return true;
					}
				}
			}
		}
	}
	return false;
}

bool check(double mid) {
	memset(visit, true, sizeof(visit));
	car temp;
	temp.x = acm.x; temp.len = acm.len + 2*mid; temp.pos = acm.pos - mid;
	for (int i=0; i<lines[0].size(); i++) {
		if (!(temp.pos >= lines[0][i].pos+lines[0][i].len || temp.pos + temp.len <= lines[0][i].pos)) return false;
	}
	return dfs(temp);
}

bool cmp(car x, car y) {
	return (x.pos < y.pos || (x.pos == y.pos && x.len < y.len));
}

int main() {
	double r;
	cin >> n >> m >> r;
	cin >> acm.x >> acm.len >> acm.pos;
	for (int i=1; i<m; i++) {
		car temp;
		cin >> temp.x >> temp.len >> temp.pos;
		lines[temp.x].push_back(temp);
	}
	for (int i=0; i<n; i++) {
		car temp1;
		temp1.x=i; temp1.len=0;temp1.pos=0;
		lines[i].push_back(temp1);
		car temp2;
		temp2.x=i; temp2.len=0;temp2.pos=r;
		lines[i].push_back(temp2);
		sort(lines[i].begin(), lines[i].end(), cmp);
	}
	double l=0;
	r = acm.pos;
	for (int i=0;i<38; i++) {
		double mid = (l+r)/2;
		if (check(mid)) l = mid;
		else r=mid;
	}
	if (!check(l)) cout << "Impossible" << endl;
	else printf("%.6f\n", l);
}
