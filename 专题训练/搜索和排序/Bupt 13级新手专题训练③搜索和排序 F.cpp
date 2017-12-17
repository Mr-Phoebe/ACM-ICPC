#include<iostream>
#include<cstdio>
#include<algorithm>  
#include<cstring>  
  
using namespace std;
  
void swap(int a[],int i,int j)
{  
    while (i<j)
	{  
        a[i]=a[i]^a[j];  
        a[j]=a[j]^a[i];  
        a[i]=a[i]^a[j];  
        i++;  
        j--;  
    }  
}  
  
int main()
{  

    int a[33],b[33],n;  
    while(scanf("%d",&a[0])!=EOF)
	{  
        n=1;b[0]=a[0];
		cout<<a[0]<<" ";
		if(getchar()!='\n')
			while(cin>>a[n])
			{
				b[n]=a[n];
				cout<<a[n++]<<" ";
				if(getchar()=='\n')
					break;
			}   
        puts("");  
        sort(b,b+n);  
        for (int i=n-1;i>=0;i--)      
            if(a[i]==b[i])
				continue;  
            else
				for(int j=i-1;j>=0;j--) 
                if(b[i]==a[j])
				{  
                    if(!j)
					{  
                        cout<<n-i<<" ";  
                        swap(a,0,i);  
                    }  
                    else
					{  
                        swap(a,0,j);swap(a,0,i);   
                        cout<<n-j<<" "<<n-i<<" ";  
                    }  
                }    
		cout<<"0"<<endl;
    }  
  
    return 0;  
}  