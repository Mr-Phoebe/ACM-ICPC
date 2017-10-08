#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;
typedef vector<pdd> vdd;
#define ls first
#define rs second
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)

vdd gps;
vdd rr;
int ti[111];

inline double dis(pdd a, pdd b)
{
	return sqrt(pow(a.ls-b.ls, 2) + pow(a.rs-b.rs, 2));
}

double distance(const vdd& a)
{
	double ans = 0.0;
	int n = a.size();
	for(int i = 1; i < n; i++)
		ans += dis(a[i], a[i-1]);		
	return ans;
}


int main()
{
	int n, inv, x, y;
	scanf("%d %d", &n, &inv);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x, &y, &ti[i]);	
		rr.pb(mp(x, y));
	}
	for(int time = 0, m = 1; time <= ti[n-1] && m < n; time++)
	{
		if(time > ti[m])
			m++;
		if(time % inv == 0)
		{
			double xx = rr[m-1].ls + (rr[m].ls - rr[m-1].ls) * (1.0*time - ti[m-1]) / (ti[m] - ti[m-1]);
			double yy = rr[m-1].rs + (rr[m].rs - rr[m-1].rs) * (1.0*time - ti[m-1]) / (ti[m] - ti[m-1]);
			gps.pb(mp(xx, yy));
		}
	}
	gps.pb(mp(x, y));
	double realworld = distance(rr);
	double gpsworld = distance(gps);
	printf("%.14f\n", (1 - (gpsworld/realworld))*100);
	return 0;
}
