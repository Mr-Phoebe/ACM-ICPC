#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define MAXN 200
#define inf 1000000000

typedef double elem_t;

struct point3
{
    double x, y, z;
};

struct circle
{
    point3 c;
    double r;
}cir[105];

double dist_r(point3 a, point3 b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
}

double dist_c(circle a, circle b)
{
    return dist_r(a.c, b.c) - a.r - b.r;
}

elem_t prim(int n, elem_t mat [][MAXN], int* pre)
{
    elem_t min[MAXN], ret = 0;
    int v[MAXN], i, j, k;
    for (i=0;i<n;i++)
        min[i]=inf,v[i]=0,pre[i]=-1;
    for (min[j=0]=0;j<n;j++)
	{
        for (k=-1,i=0;i<n;i++)
            if (!v[i]&&(k==-1||min[i]<min[k]))
                k=i;
        for (v[k]=1,ret+=min[k],i=0;i<n;i++)
            if (!v[i] && mat[k][i]<min[i])
                min[i]=mat[pre[i]=k][i];
    }
    return ret;
}
int main()
{
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin>>cir[i].c.x>>cir[i].c.y>>cir[i].c.z>>cir[i].r;
        elem_t mat[MAXN][MAXN];
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                double temp=dist_c(cir[i], cir[j]);
                if (temp<eps)
                {
                    mat[i][j]=mat[j][i]=0;
                    continue;
                }
                mat[i][j]=mat[j][i]=temp;
            }
        }
        int pre[MAXN];
        cout<<fixed<<setprecision(3)<<prim(n,mat,pre)<<endl;
    }
}