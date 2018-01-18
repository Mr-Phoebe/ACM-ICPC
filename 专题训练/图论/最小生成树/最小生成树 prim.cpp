#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define MEM(a, v)		memset (a, v, sizeof (a))	// a for address, v for value
#define max(x, y)		((x) > (y) ? (x) : (y))
#define min(x, y)		((x) < (y) ? (x) : (y))

#define INF		(0x3f3f3f3f)
#define MAXN	(103)
#define MAXE	(MAXN*(MAXN-1)/2)

#define DEBUG	/##/

struct POINT {
	int x, y;
};

int		t, c ;
int		used[MAXN] ;
double	map[MAXN][MAXN], dist[MAXN] ;
POINT	apt[MAXN] ;

#define POW(x) ((x)*(x))
#define DINF	(1e10)

inline double getdist (int i, int j)
{
	double dis = sqrt(1.0*POW(apt[i].x - apt[j].x) + POW(apt[i].y - apt[j].y)) ;

	if (dis < 10.0 || dis > 1000.0)
		return DINF ;
	return dis ;
}

double Prim ()
{
	int i, j, iMinPath ;
	double sum, MinPath ;

	for (i = 1 ; i <= c ; ++i)
		dist[i] = map[1][i] ;

	MEM (used, 0) ;
	used[1] = true ;
	sum = 0.0 ;

	for (i = 1 ; i <= c-1 ; ++i)
	{
		MinPath = DINF ;
		for (j = 1 ; j <= c ; ++j)
			if (!used[j] && dist[j] < MinPath)
			{
				iMinPath = j ;
				MinPath = dist[j] ;
			}

		sum += MinPath ;

		if (sum >= DINF)
			break ;

		used[iMinPath] = true ;

		for (j = 1 ; j <= c ; ++j)
			if (!used[j] && dist[j] > map[iMinPath][j])
				dist[j] = map[iMinPath][j] ;
	}
	return sum ;
}

int main()
{
	int i, j ;
	int x, y ;
	double ans ;
	while (scanf ("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf ("%d", &c) ;
			for (i = 1 ; i <= c ; ++i)
			{
				scanf ("%d%d", &apt[i].x, &apt[i].y) ;
			}

			// 遍历所有点，制图
			for (i = 1 ; i <= c ; ++i)
				for (j = i+1 ; j <= c ; ++j)
				{
					map[i][j] = map[j][i] = getdist (i, j) ;
				}
			ans = Prim () ;
			if (ans >= DINF)
				puts ("oh!") ;
			else
				printf ("%.1lf\n", ans*100.0) ;
		}
	}
	return 0 ;
}

