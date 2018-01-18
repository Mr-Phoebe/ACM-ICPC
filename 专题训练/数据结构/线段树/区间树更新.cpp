#include <iostream>
#include <cstring>
#include <vector>
#define inf 50010
using namespace std;
struct Node
{
    int l , r ,flag;
    int mlen , llen , rlen;
    void init(int v)
    {
        flag = v;
        if(v)
            mlen = 0;
        else
            mlen = r-l+1;
        llen = rlen = mlen;
    }
}node[inf*5];
struct Line
{
    int s , e;
};
vector <Line> V;
void build(int l , int r , int num)
{
    node[num].flag = -1 , node[num].l = l , node[num].r = r;
    node[num].mlen = node[num].llen = node[num].rlen = r-l+1;
    if(l == r)
        return ;
    int mid = (l+r)>>1;
    build(l , mid , num<<1);
    build(mid+1 , r , (num<<1)+1);
}
void update(int l , int r , int num , int flag)
{
    if(l <= node[num].l && node[num].r <= r)
    {
        node[num].init(flag);
        return ;
    }
    if(node[num].flag != -1)
    {
        node[num<<1].init(node[num].flag);
        node[(num<<1)+1].init(node[num].flag);
        node[num].flag = -1;
    }
    int mid = (node[num].l + node[num].r)>>1;
    if(l <= mid) update(l , r , num<<1 , flag);
    if(r > mid) update(l , r ,(num<<1)+1 , flag);
   
    node[num].mlen = max(node[num<<1].rlen + node[(num<<1)+1].llen , max(node[num<<1].mlen , node[(num<<1)+1].mlen));
    node[num].llen = node[num<<1].llen;
    node[num].rlen = node[(num<<1)+1].rlen;
    if(node[num].llen == mid - node[num].l+1)
        node[num].llen += node[(num<<1)+1].llen;
    if(node[num].rlen == node[num].r - mid)
        node[num].rlen += node[num<<1].rlen;
}
int query(int num , int len)
{
    if(node[num].l == node[num].r)
    {
        if(node[num].mlen == len)
            return node[num].l;
    }
   
    if(node[num].flag != -1)
    {
        node[num<<1].init(node[num].flag);
        node[(num<<1)+1].init(node[num].flag);
        node[num].flag = -1;
    }
   
    if(node[num<<1].mlen >= len)
        return query(num<<1 , len);
    else if(node[num<<1].rlen + node[(num<<1)+1].llen >= len)
    {
        return node[num<<1].r - node[num<<1].rlen + 1;
    }
    else
        return query((num<<1)+1 , len);
}
int Bin(int k)
{
    int l = 0 , r = V.size()-1;
    while(l <= r)
    {
        int mid = (l+r)>>1;
        if(V[mid].s <= k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}
int main()
{
    int n , m;
    //freopen("C:/Users/yesterday/Desktop/1.txt" , "r" , stdin);
    //freopen("C:/Users/yesterday/Desktop/out.txt" , "w" , stdout);
    while(scanf("%d%d", &n ,&m) == 2)
    {
        char s[10];
        build(1 , n , 1);
        V.clear();
        while(m --)
        {
            scanf("%s" , s);
            if(!strcmp(s , "Reset"))
            {
                update(1 , n , 1 , 0);  
                V.clear();
                puts("Reset Now");
            }
            else if(!strcmp(s , "Free"))
            {
                int temp;
                scanf("%d" , &temp);
                int id = Bin(temp);
                if(id == -1 || V[id].e < temp)
                    puts("Reject Free");
                else
                {
                    printf("Free from %d to %d\n" , V[id].s , V[id].e);
                    update(V[id].s , V[id].e , 1 ,  0);
                    V.erase(V.begin()+id , V.begin()+id+1);
                }
            }
            else if(!strcmp(s , "New"))
            {
                int temp;
                scanf("%d" , &temp);
                if(node[1].mlen < temp)
                {
                    puts("Reject New");
                }
                else
                {
                    Line buf;
                    buf.s = query(1 , temp);
                    buf.e = buf.s + temp - 1;
                    int id = Bin(buf.s)+1;
                    V.insert(V.begin()+id , buf);
                    update(buf.s , buf.e , 1 , 1);
                    printf("New at %d\n" , buf.s);
                }
            }
            else
            {
                int temp;
                scanf("%d" , &temp);
                if(temp <= V.size()&&temp > 0)
                    printf("Get at %d\n" , V[temp-1].s);
                else
                    printf("Reject Get\n");
            }
        }
        puts("");
    }
    //system("pause");
    return 0;
}