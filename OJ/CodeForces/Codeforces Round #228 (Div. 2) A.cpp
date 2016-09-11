#include <algorithm>  
#include <iostream>  

#define maxn 111  
using namespace std;  
  
int a[maxn];  
int main()
{  
    int n;
    cin>>n;
	for(int i=0;i<n;i++) 
      cin>>a[i];  
 	sort(a,a+n);  
    while(a[n-1]!=a[0])
	{  
      	for(int i=n-1;i>0;i--)  
       		if(a[i]%a[i-1]==0)  
        		a[i]=a[i-1];  
       		else
			   a[i]%=a[i-1];  
      	sort(a,a+n);  
      	
    }    
    int sum=0;
    for(int i=0;i<n;i++)  
      sum+=a[i];  
    cout<<sum<<endl;  
    return 0;  
}   