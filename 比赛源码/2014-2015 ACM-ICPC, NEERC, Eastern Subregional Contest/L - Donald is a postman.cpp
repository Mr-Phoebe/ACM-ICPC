#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

map<string,int> M;

int n;
int pos = 1;
int ans = 0;
int main()
{
    M.insert(make_pair("Alice",1));
    M.insert(make_pair("Ariel",1));
    M.insert(make_pair("Aurora",1));
    M.insert(make_pair("Phil",1));
    M.insert(make_pair("Peter",1));
    M.insert(make_pair("Olaf",1));
    M.insert(make_pair("Phoebus",1));
    M.insert(make_pair("Ralph",1));
    M.insert(make_pair("Robin",1));

    M.insert(make_pair("Bambi",2));
    M.insert(make_pair("Belle",2));
    M.insert(make_pair("Bolt",2));
    M.insert(make_pair("Mulan",2));
    M.insert(make_pair("Mowgli",2));
    M.insert(make_pair("Mickey",2));
    M.insert(make_pair("Silver",2));
    M.insert(make_pair("Simba",2));
    M.insert(make_pair("Stitch",2));

    M.insert(make_pair("Dumbo",3));
    M.insert(make_pair("Genie",3));
    M.insert(make_pair("Jiminy",3));
    M.insert(make_pair("Kuzko",3));
    M.insert(make_pair("Kida",3));
    M.insert(make_pair("Kenai",3));
    M.insert(make_pair("Tarzan",3));
    M.insert(make_pair("Tiana",3));
    M.insert(make_pair("Winnie",3));

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int poss = M.find(s)->second;
        ans += abs(poss - pos);
        pos = poss;
    }
    cout<<ans;
    return 0;
}
