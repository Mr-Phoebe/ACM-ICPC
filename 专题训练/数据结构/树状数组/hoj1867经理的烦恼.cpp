#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int n=1000010;
int c[n];
int a[n];
int cc,nn,mm;
int lowb(int t)
{ 
    return t&(t^(t-1)); 
} 
void add(int i,int v)
{
    for(;i<=cc;c[i]+=v,i+=lowb(i));
}

int sum(int i)
{
    int s=0;
    for(;i>0;s+=c[i],i-=lowb(i));
    return s;
}

int isprime(int x)
{
	int i;

	if (x<=1) return 0;
	for (i=2;i<=sqrt(x);i++)
		if (x%i==0) return 0;
	return 1;
}


int main()
{
    int cases=0;
//	freopen("data.txt","r",stdin);
    while(scanf("%d%d%d",&cc,&nn,&mm)&&(cc||nn||mm))
    {
        int i,j;
        memset(c,0,sizeof(c));
        a[0]=0;
        int t=isprime(mm);
        for(j=1;j<=cc;j++)
        {
            if(t)
           		add(j,1);
            a[j]=mm;
        }
        printf("CASE #%d:\n",++cases);
        for(i=0;i<nn;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(x==0)
            {
                if(a[y]>0&&isprime(a[y]))
                    add(y,-1);
                a[y]+=z;
                if(a[y]>0&&isprime(a[y]))
                    add(y,1);
            }
            else
                printf("%d\n",sum(z)-sum(y-1));
        }
        cout<<endl;
    }
    return 0;
}
