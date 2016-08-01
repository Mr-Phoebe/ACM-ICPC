#include<iostream>
#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9
#define MAX_N 500

using namespace std;

long long a,b,c,x1,x2,y1,y2;

int gcd(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=b;
        b=a%b;
        a=r;
    }
    return a;
}



long long exgcd(long long m,long long n,long long &x,long long &y)
{
    long long x1,y1,x0,y0;
    x0=1;
    y0=0;
    x1=0;
    y1=1;
    x=0;
    y=1;
    long long r=m%n;
    long long q=(m-r)/n;
    while(r)
    {
        x=x0-q*x1;
        y=y0-q*y1;
        x0=x1;
        y0=y1;
        x1=x;
        y1=y;
        m=n;
        n=r;
        r=m%n;
        q=(m-r)/n;
    }
    return n;
}

long long work()
{
    long long x,y,d,lx,ly,rx,ry,yx,tx,ty;
    c=-c;
    if (a==0&&b==0)
        if (c==0)
            return min(x2-x1+1,y2-y1+1);
        else return 0;
    if (a==0)
        if (c%b==0)
        {
            y=c/b;
            if (y>=y1&&y<=y2)
                return x2-x1+1;
            else return 0;
        }
        else return 0;
    if (b==0)
        if (c%a==0)
        {
            y=c/a;
            if (x>=x1&&x<=x2)
                return y2-y1+1;
            else return 0;
        }
        else return 0;
    x=y=0;
    d=exgcd(a,b,x,y);
    if (c%d!=0)
        return 0;
    tx=x*(c/d);        //§Ý§î¨o§¢
    ty=y*(c/d);
    lx=(x1<=tx||(x1-tx)*d%b==0)?(x1-tx)*d/b:(x1-tx)*d/b+1;
    rx=(x2>=tx||(tx-x2)*d%b==0)?(x2-tx)*d/b:(x2-tx)*d/b-1;
    ly=(y1<=ty||(y1-ty)*d%a==0)?(ty-y1)*d/a:(ty-y1)*d/a-1;
    ry=(y2>=ty||(ty-y2)*d%a==0)?(ty-y2)*d/a:(ty-y2)*d/a+1;
    if (lx>rx)
        swap(lx,rx);
    if (ly>ry)
        swap(ly,ry);
    if (!(lx<=ry&&ly<=rx))
        return 0;
    return min(rx,ry)-max(lx,ly)+1;
}

int main()
{

    scanf("%d %d %d",&a,&b,&c);
    scanf("%d %d",&x1,&x2);
    scanf("%d %d",&y1,&y2);
    cout<<work()<<endl;
    return 0;
}
