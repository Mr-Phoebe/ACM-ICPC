#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double a = atan(sqrt(7.0));
	double b = atan(sqrt(7.0)/5);
	double c = a/2 - 2*b + sqrt(7.0)/4;
	double l, ans;
	int T_T;
	cin >> T_T;
	while(T_T--)
	{
		cin >> l;
		ans = l*l*c;
		printf("%.2f\n", ans);
	}
	return 0;
}