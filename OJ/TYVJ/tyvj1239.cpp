#include <cstdio>



int main()
{
	int x[110],y[110],z[110];
	int v[110];
	int n;
	int ans=0;
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&x[i],&y[i],&z[i],&v[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				int t=0;
				t|=(1<<x[i]);t|=(1<<x[j]);t|=(1<<x[k]);
				t|=(1<<y[i]);t|=(1<<y[j]);t|=(1<<y[k]);
				t|=(1<<z[i]);t|=(1<<z[j]);t|=(1<<z[k]);
				if(t==1022)
				{
					int tt=v[i]+v[j]+v[k];
					ans=(ans>tt?ans:tt);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}