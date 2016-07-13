/* ***********************************************
Author        :kuangbin
Created Time  :2014/3/2 20:02:38
File Name     :E:\2014ACM\比赛\ZOJ_March2014\I.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define Key_value ch[ch[root][1]][0]
const int MAXN = 300010;
int pre[MAXN],ch[MAXN][2],key[MAXN],size[MAXN];
int root,tot1;
int sum0[MAXN],sum1[MAXN];//该子树对应状态的gcd
int st[MAXN]; //该节点的状态
int s[MAXN],tot2;//内存池和容量
//初始节点的值和状态
int a[MAXN];
int status[MAXN];
int n,q;

long long gcd(long long a,long long b)
{
    if(b == 0)return a;
    else return gcd(b,a%b);
}
void NewNode(int &r,int father,int k,int _st)
{
    if(tot2) r = s[tot2--];
    else r = ++tot1;
    pre[r] = father;
    ch[r][0] = ch[r][1] = 0;
    key[r] = k;
    st[r] = _st;
    if(_st == 0){sum0[r] = k; sum1[r] = 0;}
    else {sum1[r] = k; sum0[r] = 0;}
    size[r] = 1;
}
void push_up(int r)
{
    int lson = ch[r][0], rson = ch[r][1];
    size[r] = size[lson] + size[rson] + 1;
    sum0[r] = sum1[r] = 0;
    sum0[r] = gcd(sum0[lson],sum0[rson]);
    sum1[r] = gcd(sum1[lson],sum1[rson]);
    if(st[r])sum1[r] = gcd(sum1[r],key[r]);
    else sum0[r] = gcd(sum0[r],key[r]);
}
void push_down(int r)
{
    
}
void Build(int &x,int l,int r,int father)
{
    if(l > r)return;
    int mid = (l + r)/2;
    NewNode(x,father,a[mid],status[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    push_up(x);
}
void Init()
{
    root = tot1 = tot2 = 0;
    ch[root][0] = ch[root][1] = size[root] = pre[root] = 0;
    sum0[root] = sum1[root] = 0;
    NewNode(root,0,0,0);
    NewNode(ch[root][1],root,0,0);
    for(int i = 0;i < n;i++)
        scanf("%d%d",&a[i],&status[i]);
    Build(Key_value,0,n-1,ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
}
void Rotate(int x,int kind)
{
    int y = pre[x];
    push_down(y);
    push_down(x);
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if(pre[y])
        ch[pre[y]][ch[pre[y]][1]==y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
    push_up(y);
}
void Splay(int r,int goal)
{
    push_down(r);
    while(pre[r] != goal)
    {
        if(pre[pre[r]] == goal)
        {
            Rotate(r,ch[pre[r]][0] == r);
        }
        else
        {
            int y = pre[r];
            int kind = ch[pre[y]][0] == y;
            if(ch[y][kind] == r)
            {
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else
            {
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    push_up(r);
    if(goal == 0)root = r;
}
int Get_kth(int r,int k)
{
    push_down(r);
    int t = size[ch[r][0]] + 1;
    if(t == k)return r;
    if(t > k)return Get_kth(ch[r][0],k);
    else return Get_kth(ch[r][1],k-t);
}
//在第pos个数后面插入一个数
void Insert(int pos,int _val,int _st)
{
    Splay(Get_kth(root,pos+1),0);
    Splay(Get_kth(root,pos+2),root);
    NewNode(Key_value,ch[root][1],_val,_st);
    push_up(ch[root][1]);
    push_up(root);
}
void erase(int r)
{
    if(!r)return;
    s[++tot2] = r;
    erase(ch[r][0]);
    erase(ch[r][1]);
}
//删除第pos个数
void Delete(int pos)
{
    Splay(Get_kth(root,pos),0);
    Splay(Get_kth(root,pos+2),root);
    erase(Key_value);
    pre[Key_value] = 0;
    Key_value = 0;
    push_up(ch[root][1]);
    push_up(root);
}
//改变第pos个数的状态
void Change(int pos)
{
    Splay(Get_kth(root,pos),0);
    Splay(Get_kth(root,pos+2),root);
    st[Key_value] ^= 1;
    push_up(Key_value);
    push_up(ch[root][1]);
    push_up(root);
}
//改变第pos个数的值
void Modify(int pos,int _val)
{
    Splay(Get_kth(root,pos),0);
    Splay(Get_kth(root,pos+2),root);
    key[Key_value] = _val;
    push_up(Key_value);
    push_up(ch[root][1]);
    push_up(root);
    
}
int Query(int L,int R,int _st)
{
    int ans ;
    Splay(Get_kth(root,L),0);
    Splay(Get_kth(root,R+2),root);
    if(_st == 0)ans = sum0[Key_value];
    else ans = sum1[Key_value];
    if(ans == 0)ans = -1;
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&q) == 2)
    {
        Init();
        char op[10];
        while(q--)
        {
            scanf("%s",op);
            if(op[0] == 'Q')
            {
                int L,R,_st;
                scanf("%d%d%d",&L,&R,&_st);
                printf("%d\n",Query(L,R,_st));
            }
            else if(op[0] == 'I')
            {
                int pos,val,_st;
                scanf("%d%d%d",&pos,&val,&_st);
                Insert(pos,val,_st);
            }
            else if(op[0] == 'D')
            {
                int pos;
                scanf("%d",&pos);
                Delete(pos);
            }
            else if(op[0] == 'R')
            {
                int pos;
                scanf("%d",&pos);
                Change(pos);
            }
            else if(op[0] == 'M')
            {
                int pos,val;
                scanf("%d%d",&pos,&val);
                Modify(pos,val);
            }
        }
    }
    return 0;
}