#include<iostream>  
#include<algorithm>  
#include<cmath>
#include<cstdio> 

using namespace std; 
 
struct TREE  
{  
    double x,y,z;  
}tree[5555];

int dis[11];  

double pow2(double x)
{
	return x*x;
}

double distancetree(struct TREE a,struct TREE b)
{
	return sqrt(pow2(a.x-b.x)+pow2(a.y-b.y)+pow2(a.z-b.z));
}


int main()  
{  
    int n=0;

    while(cin>>tree[n].x>>tree[n].y>>tree[n].z)
    {   
    	if(tree[n].x<=1e-7&&tree[n].y<=1e-7&&tree[n].z<=1e-7)
			break;
        n++;  
    }  
    for(int i=0;i<n;i++)  
    {  
        int tmin=1<<29;  
        for(int j=0;j<n;j++)  
        {  
            if(i==j)
				continue;  
            int temp=distancetree(tree[i],tree[j]);  
            tmin=min(tmin,temp);  
        }  
        dis[tmin]++;  
    }  
    for(int i=0;i<10;i++)
		printf("%4d",dis[i]); 
    cout<<endl;  
    return 0;  
}  