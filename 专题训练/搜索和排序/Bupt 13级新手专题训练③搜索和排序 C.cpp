#include<iostream>  
#include<cstring>  
#include<algorithm>  
using namespace std;  

int n,m;  
int a[10010],b[10010]; 

int binarysearch(int l,int r,const int value)
{
    int found;
    int	low,high,mid;   
    found=0;
    low=l;
    high=r-1;
    while(low<=high)
    {	
        mid=(high+low)/2;
        if (a[mid]==value)
        {
			found=1;
			break;
        }
        if (a[mid]>value)
            low=mid+1;
        else
            high=mid-1;
    }
	if(found)
        return mid;
    else
        return -1;

}


int main()  
{  
    int t=0; 

    while(cin>>n>>m&&n&&m)  
    {  
    for (int i=0;i<n;i++)  
        cin>>a[i];  
    for (int i=0;i<m;i++)  
        cin>>b[i];  
    sort(a,a+n);  
    cout<<"CASE# "<<++t<<endl;  
    for (int i=0;i<m;i++)  
    {  
        int j=binarysearch(0,n,b[i]);   
        if(j==-1)  
        	cout<<b[i]<<" not found"<<endl;  
        else
        	cout<<b[i]<<" found at "<<j+1<<endl;
    }  
    }  
    return 0;  
}  