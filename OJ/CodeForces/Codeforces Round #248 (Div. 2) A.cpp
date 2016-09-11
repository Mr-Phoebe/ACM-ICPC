#include <iostream>
#include <cstdio>

using namespace std;
int w[111];
int main()
{
	  bool s=true;
	  int n;
	  int ans=0;
	  scanf("%d",&n);
	  for(int i=0;i<n;i++)
	  {
		    scanf("%d",&w[i]);
		    w[i]/=100;
		    ans+=w[i];
		    if(w[i]==1)
      			s=false;
	  }
	  if((n%2==1)&&s)
	  {
		    printf("NO\n");
		    return 0;
	  }
	  if(n==1)
	  {
		    printf("NO\n");
		    return 0;
	  }
	  if(ans%2==0)
	    	printf("YES\n");
	  else
	    	printf("NO\n");
	  return 0;
}