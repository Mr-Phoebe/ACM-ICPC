#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000003];
int main()
{
//	freopen("data.txt","r",stdin);
    int n,m,sum;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        scanf("%d",&a[m]);
    }
    sum=0;
    m=0;
    for(int i=1;i<=n;i++)
    {
        m=(m+5+a[i])%30;
        if(m>25&&m<30)
        {
            sum+=30-m;
            if(i!=n)
                m=0;
        }
    }
    if(m>25&&m<30)
        sum-=30-m;
    cout<<sum<<endl;
    return 0;
}
