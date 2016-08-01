#include<iostream>
#include<algorithm>
 
using namespace std;


int main()
{
    char meth;
    int c[6]={0},ans[33]={0};
    int n,j=0,top=0,num=1;
    cin>>n;
    getchar();
    while(n--)
    {
        meth=getchar();
        switch(meth)
        {
        case 'A':
            ans[j++]=num++;
            break;
        case 'B':
            if(top>=4)
            {
                cout<<"No"<<endl;
                return 0;
            }
            else
                c[top++]=num++;
            break;
        case 'C':
            if(top<=0)
            {
                cout<<"No"<<endl;
                return 0;
            }
            else
            {
                ans[j++]=c[top-1];
                c[--top]=0;
            }
            break;
        default:
            {
				n++;
				continue;
			}
        }
    }
    cout<<"Yes"<<endl;
    for(j=0;j<num-1;j++)
        cout<<ans[j]<<endl;      
	return 0;

}
