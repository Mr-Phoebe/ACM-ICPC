#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int _1[] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
int _2[] = {0,3,6,6,5,5,5,7,6,6};
int a[2000];

int gao(int n)
{
    if(n == 1000) return 11;
    if(n%100 == 0) return gao(n/100)+7;
    if(n > 100) return gao(n/100)+10+gao(n%100);
    if(n%10 == 0) return _2[n/10];
    if(n > 20) return _2[n/10]+_1[n%10];
    return _1[n];
}

int main()
{
    int n, T_T;
    for(int i = 1; i <= 1000; i++)
        a[i] = a[i-1]+gao(i);
    cin >> T_T;
    while(T_T--)
    {
        cin >> n;
        printf("%d\n", a[n]);
    }
    return 0;
}