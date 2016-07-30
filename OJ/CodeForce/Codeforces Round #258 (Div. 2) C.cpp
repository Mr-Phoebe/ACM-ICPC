#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}

int main()  
{  
    int T;  
    ll n,k,d1,d2;  
    ll x1,x2,x3;  
  
    read(T);  
    while(T--)  
    {  
        read(n);read(k);read(d1)&read(d2);  
        if(n%3!=0)  
        {  
            printf("no\n");  
            continue;  
        }  
        int flag=0;  
        for(int i=0;i<=3;i++)  
        {  
            if(i==0)  
            {  
                if((k+d2+2*d1)>=0&&(k+d2+2*d1)%3==0)  
                {  
                    x1=(k+d2+2*d1)/3;  
                    x2=x1-d1;  
                    x3=x2-d2;  
                }  
                else continue;  
            }  
            else if(i==1)  
            {  
                if((k-d2+2*d1)>=0&&(k-d2+2*d1)%3==0)  
                {  
                    x1=(k-d2+2*d1)/3;  
                    x2=x1-d1;  
                    x3=x2+d2;  
                }  
                else continue;  
            }  
            else if(i==2)  
            {  
                if((k+d2-2*d1)>=0&&(k+d2-2*d1)%3==0)  
                {  
                    x1=(k+d2-2*d1)/3;  
                    x2=x1+d1;  
                    x3=x2-d2;  
                }  
                else continue;  
            }  
            else if(i==3)  
            {  
                if((k-d2-2*d1)>=0&&(k-d2-2*d1)%3==0)  
                {  
                    x1=(k-d2-2*d1)/3;  
                    x2=x1+d1;  
                    x3=x2+d2;  
                }  
                else continue;  
            }  
            if(x1>=0&&x2>=0&&x3>=0&&x1<=n/3&&x2<=n/3&&x3<= n/3)  
                flag=1;  
        }  
        if(flag)  
            printf("yes\n");  
        else  
            printf("no\n");  
    }  
    return 0;  
}  