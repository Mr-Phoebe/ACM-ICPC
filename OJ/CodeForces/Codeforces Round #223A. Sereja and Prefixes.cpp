#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
 
const int maxm = 100005;

inline int getint()
{
     int ans(0); char w = getchar();
     while('0' > w || w > '9')w = getchar();
     while('0' <= w && w <= '9')
     {
         ans = ans * 10 + w - '0';
         w = getchar();
     }
     return ans;
 } 
 
 int n, m;
 struct build
 {
     int ord, x, l, c;
	 long long a, b;
 }hell[maxm];
 int sq[maxm];
 
 int main()
 {
     m = getint();
     for(int i = 1; i <= m; ++i)
     {
         hell[i].ord = getint();
         if(hell[i].ord == 1)
		{
             hell[i].x = getint(); 
             hell[i].a = hell[i].b = hell[i - 1].b + 1LL;
             if(hell[i].a < maxm)
			 	sq[hell[i].a] = hell[i].x;
         }
         else{
             hell[i].l = getint(); hell[i].c = getint();
             hell[i].a = hell[i - 1].b + 1LL;
             hell[i].b = hell[i - 1].b + (long long)hell[i].l * (long long)hell[i].c;
             if(hell[i].a < maxm)
             {
                 int now = hell[i].a;
                 for(int j = 1; j <= hell[i].c && now < maxm; ++j)
                     for(int k = 1; k <= hell[i].l && now < maxm; ++k)
                         sq[now++] = sq[k];
             }
         }
     }
     
     n = getint();
     int h = 1; long long x;
    for(int i = 1; i <= n; ++i)
     {
         cin >> x;
         while(!(hell[h].a <= x && hell[h].b >= x))++h;
         if(x <= 100000)printf("%d ", sq[x]);
         else{
             if((x - hell[h - 1].b) % (long long)hell[h].l != 0)
                 cout << sq[(x - hell[h - 1].b) % (long long)hell[h].l] << ' ';
             else cout << sq[hell[h].l] << ' ';
         }
     }
     return 0;
 }