#include<iostream>
#include <cstdio>  
#include <set>  
#include <vector>  
using namespace std;  
  
const int MAXN=111111;  
  
int n;  
int num[MAXN];  
int guess[MAXN];  
vector<int> que;  
multiset<int> cmp;  
  
  
int strong()
{
	int ans=0;
 	for (int i=0;i<n;i++)
 	{
	 	if(num[i]==guess[i])
		 	ans++;
	 	else
	 	{  
		 	que.push_back(num[i]);
		 	cmp.insert(guess[i]);  
		 }
	 }
	 return ans;
}
  
int weak()
{
	int ans=0;
	multiset<int>::iterator iter;
	for(int i=0;i<que.size();i++)
	{  
		iter=cmp.find(que[i]);  
		if (iter!=cmp.end())
		{  
			ans++;
			cmp.erase(iter);  
		}
	}
	cmp.clear();que.clear();
	return ans;
} 
  
int main()
{  
    int T=0;multiset<int>::iterator it;
    while(cin>>n,n!=0)
	{  
        for(int i=0;i<n;i++)  
            cin>>num[i];  
        cout<<"Game "<<++T<<":"<<endl;  
        while(1)
		{  
            for(int i=0;i<n;i++)  
                cin>>guess[i];  
            if(!guess[0])
				break;
			int st=strong(),we=weak();
            cout<<"    ("<<st<<","<<we<<")"<<endl;;  
        }  
    }  
  
    return 0;  
}  
