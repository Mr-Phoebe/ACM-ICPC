#include <stdio.h>  
#define rep(i,j,k) for(int i=(j); i<k; i++)  
#define maxn 100010  
int a[maxn],b[maxn],c[maxn];  

int main(void)
{
	int n,m;  
    scanf("%d%d",&n,&m);  
    rep(i,0,m)  
    scanf("%d%d%d",&a[i],&b[i],&c[i]);  
    int sum = 0;  
    rep(i,0,m)
	{
		if(a[i] == b[i])
			continue;  
		rep(j,0,m)
		{
			if(a[j]==b[j])
				continue;
			if(b[i]==a[j])  
				if(c[i] >= c[j])
				{
					c[i] -= c[j];
					a[j] = a[i];
					if(a[j] == b[j])
						c[j] = 0;  
				}
			else
			{
				c[j] -= c[i];
				b[i] = b[j];
				if(a[i] == b[j])
					c[i] = 0;  
			}
			else if(a[i] == b[j])
			{
				if(c[i] >= c[j])
				{
					c[i] -= c[j];
					b[j] = b[i];
					if(a[j] == b[j])
						c[j] = 0;
				}  
				else
				{
					c[j] -= c[i];
					a[i] = a[j];
					if(a[i] == b[i])
						c[i] = 0;
				} 
			}
		} 
	}
	rep(i,0,m)
		sum += c[i];
	printf("%d\n",sum);  
    return 0;  
}  