#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


map<int,int> cnt;
    
int main()
{
    int n;
    cin >> n;
	vector<int> home(n,0),away(n,0);
    for(int i = 0 ; i < n; ++ i )
	{
        cin >> home[i] >> away[i];
        if(cnt.find(home[i]) == cnt.end()) cnt.insert(make_pair(home[i],1));
        else cnt[home[i]] ++ ;
    }
    for(int i = 0 ; i  < n ; ++ i)
        cout<<n-1+cnt[away[i]]<<" "<<n-1-cnt[away[i]]<<endl;
    return 0; 
}