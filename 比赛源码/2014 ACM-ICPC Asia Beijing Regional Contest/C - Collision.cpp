#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define maxn 10
#define maxk 100

using namespace std;

struct Ball
{
    int y;
    int x;
    int dy;
    int dx;
};
Ball a,b;
int n,m,t;
int main()
{
    scanf("%d",&t);
    for(int cas = 1;cas <=t;cas++)
    {
        a.dy = a.dx = b.dy = b.dx = 1;
        scanf("%d%d",&n,&m);
        scanf("%d%d%d%d",&a.y,&a.x,&b.y,&b.x);

        printf("Case #%d:\n",cas);

        bool flag = false;

        for(int step = 1;step<=1000000;step++)
        {
            if(a.x == 0)a.dx = 1;if(a.x == m)a.dx = -1;
            if(a.y == 0)a.dy = 1;if(a.y == n)a.dy = -1;
            if(b.x == 0)b.dx = 1;if(b.x == m)b.dx = -1;
            if(b.y == 0)b.dy = 1;if(b.y == n)b.dy = -1;

            double t1= 10000000.0,t2= -10000000.0;

            if(a.dx-b.dx != 0)
            {
                t1 = double(a.x-b.x)/double(b.dx-a.dx);
            }
            if(a.dy-b.dy != 0)
            {
                t2 = double(a.y-b.y)/double(b.dy-a.dy);
            }
           // cout<<t1<<' '<<t2<<endl;
            if( fabs(t1-t2)<1e-8 ||(a.dy == b.dy && a.y == b.y) || (a.dx == b.dx && a.x == b.x))
            {
                double ansy,ansx;
                if(a.dx != b.dx)
                {
                    ansy = a.y+t1*a.dy;
                    ansx = a.x+t1*a.dx;
                }
                else
                {
                    ansy = a.y+t2*a.dy;
                    ansx = a.x+t2*a.dx;
                }
                if(ansy<=n+1e-8 && ansy>=0-1e-8 && ansx<=m+1e-8 && ansx>=0-1e-8)
                {
                    printf("%.1lf %.1lf\n",ansy,ansx);
                    flag = true;
                    break;
                }
            }
            int ret = 1000000;

            if(a.dx == -1)
            {if(a.x>0)ret= min(ret,a.x);}
            else {if(m-a.x>0) ret = min(ret,m-a.x);}

            if(b.dx == -1)
            {if(b.x>0)ret = min(ret,b.x);}
            else {if(m-b.x>0) ret = min(ret,m-b.x);}

            if(a.dy == -1)
            {if(a.y>0)ret= min(ret,a.y);}
            else {if(n-a.y>0) ret = min(ret,n-a.y);}

            if(b.dy == -1)
            {if(b.y>0)ret = min(ret,b.y);}
            else {if(n-b.y>0) ret = min(ret,n-b.y);}
//cout<<ret<<endl;
            a.x+=a.dx*ret;
            a.y+=a.dy*ret;
            b.x+=b.dx*ret;
            b.y+=b.dy*ret;
//system("pause");
          //  cout<<a.x<<' '<<a.y<<endl;
           // cout<<b.x<<' '<<b.y<<endl;
        }
        if(!flag) printf("Collision will not happen.\n");
    }
}
