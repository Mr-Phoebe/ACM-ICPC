#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char s[10000];
int line;
int len;
string S;

string toHex(int x,int digits)
{
    string ret;
    while(x > 0)
    {
        int tmp = x % 16;
        if(tmp > 9) ret.insert(0,1,tmp-10+'a');
        else ret.insert(0,1,tmp+'0');

        x /= 16;
    }
    while(ret.size() < digits) ret.insert(0,1,'0');
    return ret;
}

char trans(char x)
{
    if(x >= 'a' && x <= 'z') return x - 'a' + 'A';
    if(x >= 'A' && x <= 'Z') return x - 'A' + 'a';
    return x;
}

int main()
{
    //freopen("data000.txt","w",stdout);

    while(cin.getline(s,5000))
    {
        line = 0;
        len = strlen(s);

        bool flag = true;
        int pos = 0;
        while(flag)
        {
            if(pos >= len) break;
            cout<<toHex(line,4)<<": ";
            line += 16;
            S.clear();
            for(int i=0;i<16;i++)
            {
                if(pos >= len)
                {
                    flag = false;
                    cout<<"  ";
                }
                else
                {
                    S.append(1,trans(s[pos]));
                    cout<<toHex(s[pos],2);
                }
                if(i % 2 == 1) cout<<" ";
                pos++;
            }
            cout<<S<<endl;
        }
    }
    return 0;
}