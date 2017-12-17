#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000 + 10;
const double eps = 1e-8;

struct SEG
{
	int x1, y1, x2, y2;
	double x;
};

SEG seg[N];

bool operator < (const SEG& a, const SEG& b)
{
	return a.x < b.x;
}

int main()
{
	int res, n, t, w, tmp, i, j;
	double x;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d %d", &seg[i].x1, &seg[i].y1);
			if (i > 0)
			{
				seg[i-1].x2 = seg[i].x1;
				seg[i-1].y2 = seg[i].y1;
			}
		}
		seg[n-1].x2 = seg[0].x1;
		seg[n-1].y2 = seg[0].y1;
		for (i=j=0; i<n; i++)
			if (seg[i].y1 == 0 && seg[i].y2 == 0)
			{
				if (seg[i].x1 > seg[i].x2)
				{
					tmp = seg[i].x1;
					seg[i].x1 = seg[i].x2;
					seg[i].x2 = tmp;
				}
				seg[j] = seg[i];
				seg[j++].x = seg[i].x1;
			}
			else if (seg[i].y1 >= 0 && seg[i].y2 >= 0 || seg[i].y1 < 0 && seg[i].y2 < 0) continue;
			else
			{
				seg[j] = seg[i];
				seg[j++].x = (seg[i].x1 * seg[i].y2 - seg[i].y1 * seg[i].x2) / double(seg[i].y2 - seg[i].y1);
			}
		n = j;
		sort(seg, seg + n);
		res = 0;
		w = 0;
		x = -1000000;
		for (i=0; i<n; i++)
		{
			if (seg[i].x > x + eps && w > res) res = w;
			if (seg[i].y1 == seg[i].y2) 
			{
				if (seg[i].x2 > x) x = seg[i].x2;
			}
			else
			{
				if (seg[i].y1 < seg[i].y2) w --; else w ++;
				if (seg[i].x > x) x = seg[i].x;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
