#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int t,n,l,r;


int main()
{
        int i;
        int ans;
        scanf("%d",&t);
		while(t--)
        {
                scanf("%d %d %d",&n,&l,&r);
                int temp=n/r;
                if(r*temp!=n&&n<l*(temp+1))
                {
                	cout<<"No"<<endl;
                }
                else
                {
                	cout<<"Yes"<<endl;
                }
        }
        return 0;
}