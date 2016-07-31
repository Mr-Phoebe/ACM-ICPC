#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 10
#define maxk 100

using namespace std;

int t,n,m,k;

int a[maxn][maxn];
struct C
{
    int id;
    int num;
    bool operator <(const C &x) const
    {
        return num>x.num;
    }
}c[maxk];

bool check()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i][j] == a[i][j-1] || a[i][j] == a[i][j+1] || a[i][j] == a[i-1][j] || a[i][j] == a[i+1][j]) return false;

    return true;
}

void print()
{
    printf("YES\n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        printf("%d%c",a[i][j],j==m?'\n':' ');
}
void solve1()
{
    memset(a,0,sizeof(a));

    int Index = 1;
    C temp;
    temp = c[Index];

    for(int i=1;i<=n;i++)
        for(int j=i%2==0?2:1;j<=m;j+=2)
    {
        if(temp.num == 0) {Index++;temp = c[Index];}
        a[i][j] = c[Index].id;
        temp.num--;
    }
    for(int i=1;i<=n;i++)
        for(int j=(i+1)%2==0?2:1;j<=m;j+=2)
    {
        if(temp.num == 0) {Index++;temp = c[Index];}
        a[i][j] = c[Index].id;
        temp.num--;
    }
}

void solve2()
{
    memset(a,0,sizeof(a));

    int Index = 1;
    C temp;
    temp = c[Index];

    for(int i=2;i<=m+n;i+=2)
        for(int j=1;j<i;j++)
        if(i-j>=1 && i-j<=n && j>=1 && j<=m)
        {
            if(temp.num == 0) {Index++;temp = c[Index];}
            a[i-j][j] = c[Index].id;
            temp.num--;
        }

    for(int i=3;i<=m+n;i+=2)
        for(int j=1;j<i;j++)
        if(i-j>=1 && i-j<=n && j>=1 && j<=m)
        {
            if(temp.num == 0) {Index++;temp = c[Index];}
            a[i-j][j] = c[Index].id;
            temp.num--;
        }
}

void solve3()
{
    memset(a,0,sizeof(a));

    int Index = 1;
    C temp;
    temp = c[Index];

    for(int i=3;i<=m+n;i+=2)
        for(int j=1;j<i;j++)
        if(i-j>=1 && i-j<=n && j>=1 && j<=m)
        {
            if(temp.num == 0) {Index++;temp = c[Index];}
            a[i-j][j] = c[Index].id;
            temp.num--;
        }

    for(int i=2;i<=m+n;i+=2)
        for(int j=1;j<i;j++)
        if(i-j>=1 && i-j<=n && j>=1 && j<=m)
        {
            if(temp.num == 0) {Index++;temp = c[Index];}
            a[i-j][j] = c[Index].id;
            temp.num--;
        }
}
int main()
{
    scanf("%d",&t);
    for(int cas = 1;cas <=t;cas++)
    {
        printf("Case #%d:\n",cas);
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&c[i].num);
            c[i].id = i;
        }

        sort(c+1,c+1+k);
        solve1();
        if(check()) {print();continue;}
        solve2();
        if(check()) {print();continue;}
        solve3();
        if(check()) {print();continue;}
        printf("NO\n");
    }
}
