#include<iostream>
#include<string>

using namespace std;

long long ansb=1;
string p,temp1,temp2;

int comparenum(const string &a,const string &b)
{
	if(a.length()>b.length())
		return 1;
	else if(a.length()<b.length())
		return -1;
	else 
	{
		for(int i=0,j=b.length()-1;i<a.length(),j>=0;i++,j--)
			if(a.at(i)>b.at(j))
				return 1;
			else if(a.at(i)<b.at(j))
				return -1;
	}
	return 0;
}




int main()
{
	cin>>p;
 	for(int i=p.length()-1;i>=1;i--)  
    {  
        temp2=p.substr(0,i);  
        temp1+=p[i];
        if(p.at(i)>'0'&&comparenum(temp2,temp1)>=0)  
        {  
            ansb++;
            temp1.clear();  
        }  
    }  
    cout<<ansb<<endl;  
	
}
