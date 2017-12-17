#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 5100;
int v[maxn], u[maxn], w[maxn];         //u,�߶���ʼ�㡣v,�߶��յ㡣w,Ȩֵ�� 
int r[maxn];        //�������ţ����ڼ������ 
int p[maxn];                           //���鼯 

int cmp(const int i, const int j)   //������� 
{
    return w[i] < w[j];
}

int find(int x)
{
    return p[x] == x? x : p[x] = find(p[x]);
}//find


int Kruskal(int n, int m)
{
    int ans = 0;
    for(int i = 0 ; i < n; i++) p[i] = i;     //��ʼ�����鼯 
    for(int i = 0 ; i < m; i++) r[i] = i;     //��ʼ������� 
    sort(r, r+m, cmp);
    for(int i = 0; i < m ; i++)
    {
        int e = r[i]; int x = find(v[e]); int y = find(u[e]);
        if(x!=y)
        {
            ans += w[e];
            p[x] = y;        
        } //���ڲ�ͬ���ϣ��ϲ��� 
    }
    return ans;
}

void init()
{
    memset(v, 0, sizeof(v));
    memset(u, 0, sizeof(u));
    memset(w, 0, sizeof(w));
    memset(r, 0, sizeof(r));
}//init


int main()
{
    int i;
    int n, m;
    while(~scanf("%d", &n), n)
    {
        init();      //Ԥ���� 
        m = n*(n-1)/2; 
        for(i = 0 ; i < m ; i++)
        {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            u[i]--;
            v[i]--;            //ע�����Ҫ��1����Ϊ���Ǵ��㿪ʼ��ŵ� 
        }
        printf("%d\n", Kruskal(n, m));
    }
    return 0;
}