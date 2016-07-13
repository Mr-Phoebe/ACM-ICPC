#include<cstdio>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
  
int a[5010], b[5010], c[5010], s[10];  
  
int dis(int x1, int y1, int z1, int x2, int y2, int z2)  
{  
    return (int)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));  
}  
  
int main()  
{  
    int n = 0, i, j, k, minn;  
    freopen("data.txt","r",stdin);
    while (scanf("%d%d%d", &a[n], &b[n], &c[n]), a[n] || b[n] || c[n])  
        ++n;  
    for (i = 0; i < n; ++i)  
    {  
        minn = 10;  
        for (j = 0; j < n; ++j)  
            if (i != j) minn = min(minn, dis(a[i], b[i], c[i], a[j], b[j], c[j]));  
        k = minn;  
        if (k < 10) ++s[k];  
    }  
    for (i = 0; i < 10; ++i)  
        printf("%4d", s[i]);  
    putchar(10);///ÎÞÓï¡£¡£
	return 0;  
}  