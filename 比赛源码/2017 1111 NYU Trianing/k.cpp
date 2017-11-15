#include <bits/stdc++.h>

using namespace std;
#define int long long
#define EPS 1e-8

class pt2{
public:
	double x,y;
	pt2(){};
	pt2(double _x, double _y) { x = _x; y = _y;}
	pt2 vec2(const pt2 &p){ return pt2(p.x - x, p.y - y); }
	double len(){ return sqrt(x*x + y*y); };
	double dist(const pt2 &p){
		double dx = x - p.x;
		double dy = y - p.y;
		return sqrt(dx*dx + dy *dy);
	}
	double cross(const pt2 &p) { return x*p.y - y*p.x;}
	pt2 operator + (const pt2 &p) {return pt2(x + p.x, y + p.y); }
	pt2 operator - (const pt2 &p) {return pt2(x - p.x, y - p.y); }
};

bool operator< (const pt2 & p, const pt2 &q) {
	if (abs(p.x - q.x) <= EPS) return p.y < q.y;
	return p.x < q.x;
}

int side(pt2 o, pt2 a, pt2 b){
	pt2 va = o.vec2(a), vb = o.vec2(b);
	double d = va.cross(vb);
	if(abs(d) <= EPS) return 0;
	return d > 0 ? 1: -1;
}

int N, M;
pt2 pts[1005];
vector<pt2> hull;
void convexHull(){
	sort(pts, pts + N);
	vector<pt2> hl[2];
	for(int t=0;t<2;t++){
		int sn = t? -1:1;
		vector<pt2> &hu = hl[t];
		for(int i=0;i<N;i++){
			pt2 c = pts[i];
			while(hu.size() >= 2 && side(hu[hu.size()-2], hu.back(), c) != sn) hu.pop_back();
			hu.push_back(c);
		}
	}
	for(int i=hl[1].size() - 2; i >= 1; i--) hl[0].push_back(hl[1][i]);
	hull = hl[0];
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	int m[M], t[M];
	for(int i=0;i<M;i++) cin >> m[i] >> t[i];
	double x,y;
	for(int i=0;i<N;i++){
		cin >> x >> y;
		pts[i] = pt2(x,y);
	}
	convexHull();
	double per = 0;
	for(int i=0;i<hull.size()-1;i++){
		per += hull[i].dist(hull[i+1]);
	}
	per += hull[0].dist(hull[hull.size()-1]);
	int ans = ceil(per);
	int dp[ans + 5];
	for(int i=1;i<=ans+4;i++) dp[i] = 1e8;
	dp[0] = 0;
	for(int i=0;i<M;i++){
		int cur = m[i];
		if(cur > ans) cur = ans;
		int tim = t[i];
		for(int j=ans - cur; j >= 0;j--){
			if(j + cur != ans) dp[j+cur] = min(dp[j+cur], dp[j+cur+1]);
			dp[j + cur] = min(dp[j + cur], dp[j] + tim);
		}
		for(int j=cur-1;j>=0;j--) dp[j] = min(dp[j+1], dp[j]);
		//for(int j=0;j<=ans;j++) cout << dp[j] << " ";
		//cout << endl;
	}
	cout << dp[ans] << endl;
	return 0;
}
			
