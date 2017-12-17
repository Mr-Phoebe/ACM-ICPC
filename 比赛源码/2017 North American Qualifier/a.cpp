#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;
#define ls first
#define rs second
#define mp(x, y) make_pair(x, y)
const double eps = 1e-8;

int n, m, r;
double px[55], py[55];
double la[20], lb[20], lc[20];
bitset<20> pos[55];

double in(double x, double y)
{
	if(x*x + y*y - double(r)*r > eps)
		return false;
	return true;
}

pdd cross(double a1, double b1, double c1, double a2, double b2, double c2)
{
	return mp((c2*b1-c1*b2)/(a1*b2-a2*b1), (c2*a1-c1*a2)/(b1*a2-b2*a1));
}

bool para(double a1, double b1, double a2, double b2)
{
	if(b1*a2-b2*a1 == 0)	return true;
	return false;
}

int lr(double a, double b, double c, double x, double y)
{
	return a*x+b*y+c > 1e-4;
}

int main()
{

	scanf("%d %d %d", &n, &m, &r);
	for(int i = 0; i < n; i++)
		scanf("%lf %lf", &px[i], &py[i]);
	for(int i = 0; i < m; i++)
		scanf("%lf %lf %lf", &la[i], &lb[i], &lc[i]);
		
	for(int i = 0; i < n; i++)
	{
		pos[i].reset();
		for(int j = 0; j < m; j++)
			pos[i].set(j, lr(la[j], lb[j], lc[j], px[i], py[i]));
	}
	int part = 2;
	for(int i = 1; i < m; i++)
	{
		int num = 0;
		for(int j = 0; j < i; j++)
		{
			if(para(la[i], lb[i], la[j], lb[j]))
				continue;
			pdd po = cross(la[i], lb[i], lc[i], la[j], lb[j], lc[j]);
			if(in(po.ls, po.rs))
				num++;
		}
		part += num+1;
		if(part > n)
		{
			puts("no");
			return 0;
		}
	}
	if(part != n)
	{
		puts("no");
		return 0;
	}
	bitset<20> tmp;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			tmp = pos[i] ^ pos[j];
			if(tmp.count() == 0)
			{
				puts("no");
				return 0;
			}
		}
	}
	puts("yes");
	return 0;
}
