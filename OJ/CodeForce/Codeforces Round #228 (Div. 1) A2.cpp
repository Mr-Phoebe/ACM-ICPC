#include <algorithm>  
#include <iostream>  
#define maxn 111  

using namespace std;  
  
int x[maxn];  
int main(void)
{

    int n,i,c;  
    cin>>n; 
	int count[maxn]={0};  
	for(i=0;i<n;i++)  
	cin>>x[i];  
	sort(x,x+n);  
  
	int k=0;   
	for(i=0;i<n;i++)  
		if(!x[i])
			count[k++]=1;  
		else
			break;  
        
	if(i==n)
	{  
		cout<<k<<endl;  
		return 0;  
	}  
	else
	{  
		for(int j=i;j<n;j++)
		{  
			for(c=0;c<k;c++)
			{  
				if(count[c]<=x[j])
				{  
					count[c]++;  
					break;  
				}  
			}	  
			if(c==k)
			{  
				count[k]=1;  
				k++;  
			}  
		}  
        
	}  
    cout<<k<<endl;  
    return 0;  
}   