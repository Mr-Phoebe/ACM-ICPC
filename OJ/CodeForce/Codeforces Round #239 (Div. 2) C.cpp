#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int gcd ( int a, int b )
{
    return b == 0 ? a : gcd(b, a % b);
}


 void test ( int xa, int ya, int xb, int yb )
{
    if ( xa == xb || ya == yb )
        return;
    printf ( "YES\n" );
    printf ( "0 0\n" );
    printf ( "%d %d\n", xa, ya );
    printf ( "%d %d\n", xb, yb );
    exit(0);
    return ;
}


int main ()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int x=1;x<a;x++)
	{
        for(int y=1;y<a;y++)
		{
            if(x*x+y*y==a*a)
			{
                int g=gcd(x, y);
                int dx=x/g,dy=y/g,u=dx*dx+dy*dy;
                int v=b*b,ratio=v/u,k=(int)sqrt(ratio);
                if(v%u)   //不能同步放缩 
                    continue;
                if(k*k!=ratio) //不是整边 
                    continue;
                test(x, y, dy * k, -dx * k);
                test(x, y, -dy * k, dx * k);
            }
        }
    }
    puts("NO");
    return 0;
}