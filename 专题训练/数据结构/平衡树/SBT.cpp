#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN=111111;
struct SBT
{
    int left,right,size,key;
    void Init()
    {
        left=right=0;
        size=1;
    }
}tree[MAXN];
int tot,root;
void left_rotate(int &x)//左旋
{
    int y=tree[x].right;
    tree[x].right=tree[y].left;
    tree[y].left=x;
    tree[y].size=tree[x].size;
    tree[x].size=tree[tree[x].left].size+tree[tree[x].right].size+1;
    x=y;
}
void right_rotate(int &x)//右旋
{
    int y=tree[x].left;
    tree[x].left=tree[y].right;
    tree[y].right=x;
    tree[y].size=tree[x].size;
    tree[x].size=tree[tree[x].left].size+tree[tree[x].right].size+1;
    x=y;
}
void maintain(int &x,int flag)
{
    if(flag==0)
    {
        if(tree[tree[tree[x].left].left].size > tree[tree[x].right].size)
           right_rotate(x);
        else if(tree[tree[tree[x].left].right].size > tree[tree[x].right].size)
            left_rotate(tree[x].left),right_rotate(x);
        else return;
    }
    else
    {
        if(tree[tree[tree[x].right].right].size > tree[tree[x].left].size)
            left_rotate(x);
        else if(tree[tree[tree[x].right].left].size > tree[tree[x].left].size)
            right_rotate(tree[x].right),left_rotate(x);
        else return;
    }
    maintain(tree[x].left,0);
    maintain(tree[x].right,1);
    maintain(x,0);
    maintain(x,1);
}
//插入元素，相同元素放在右子树中
void insert(int &x,int key)
{
    if(x==0)
    {
        x=++tot;
        tree[x].Init();
        tree[x].key=key;
    }
    else
    {
        tree[x].size++;
        if(key<tree[x].key)insert(tree[x].left,key);
        else insert(tree[x].right,key);
        maintain(x,key>=tree[x].key);
    }
}
//删除key值的元素
int del(int &x,int key)
{
    if(!x)return 0;
    tree[x].size--;
    if(key==tree[x].key || (key<tree[x].key&&tree[x].left==0)
       || (key>tree[x].key&&tree[x].right==0))
    {
        if(tree[x].left && tree[x].right)
        {
            int p=del(tree[x].left,key+1);
            tree[x].key=tree[p].key;
            return p;
        }
        else
        {
            int p=x;
            x=tree[x].left+tree[x].right;
            return p;
        }
    }
    else return del(key<tree[x].key?tree[x].left:tree[x].right,key);
}
//**************
//得到前驱，小于
//返回前驱的节点编号
//**************
int get_pre(int &r,int y,int k)
{
    if(r==0)return y;
    if(k>tree[r].key)//加个等号就是小于等于
        return get_pre(tree[r].right,r,k);
    else return get_pre(tree[r].left,y,k);
}

//**************
//得到后继，大于
//返回后继的节点编号
//*********
int get_next(int &r,int y,int k)
{
    if(r==0)return y;
    if(k<tree[r].key)//加个等号就是大于等于
        return get_next(tree[r].left,r,k);
    else return get_next(tree[r].right,y,k);
}
//**************
//查找是否存在key值为k的元素
//不存在返回0，存在返回节点编号
//***************
int find(int t,int k)
{
    while(t && k!=tree[t].key)
        t=k<tree[t].key?find(tree[t].left,k):find(tree[t].right,k);
    return t;
}
//调试，按顺序输出
void inorder(int &x)
{
    if(x==0)return;
    else
    {
        inorder(tree[x].left);
        cout<<" "<<tree[x].key<<" "<<tree[x].size<<endl;
        inorder(tree[x].right);
    }
}

//***********
//得到前驱，返回的是小于v的key值，不存在v
//**********
int Pred(int t,int v)
{
    if(!t)return v;
    if(v<=tree[t].key)return Pred(tree[t].left,v);
    else
    {
        int tmp=Pred(tree[t].right,v);
        return v==tmp?tree[t].key:tmp;
    }
}
//***********
//得到后继，返回的是大于v的key值，不存在v
//**********
int Succ(int t,int v)
{
    if(!t)return v;
    if(v>=tree[t].key)return Succ(tree[t].right,v);
    else
    {
        int tmp=Succ(tree[t].left,v);
        return v==tmp?tree[t].key:tmp;
    }
}

//得到第k大的元素
int get_Kth(int &x,int k)
{
    if(k<=tree[tree[x].left].size)
       return get_Kth(tree[x].left,k);
    if(k>tree[tree[x].left].size+1)
       return  get_Kth(tree[x].right,k-tree[tree[x].left].size-1);
    return tree[x].key;
}

//取最大值
//返回最大值的节点编号
int Get_Max(int x)
{
    while(tree[x].right)x=tree[x].right;
    return x;
}
//取最小值
//返回最小值的节点编号
int Get_Min(int x)
{
    while(tree[x].left)x=tree[x].left;
    return x;
}

const int MOD=1000000;
int main()
{
    int n,a,b;
    while(scanf("%d",&n)==1)
    {
        root=tot=0;//这个初始化一定不要忘记
        int flag;
        int ans=0;
        while(n--)
        {
            scanf("%d%d",&a,&b);
            if(root==0)//空的
            {
                flag=a;
                insert(root,b);
            }
            else
            {
                if(a==flag){insert(root,b);}
                else
                {
                    if(find(root,b))
                    {
                        del(root,b);
                        continue;
                    }
                    int t1=get_pre(root,0,b);
                    int t2=get_next(root,0,b);
                    if(t1==0)
                    {
                        ans+=abs(tree[t2].key-b);
                        del(root,tree[t2].key);
                        ans%=MOD;
                    }
                    else if(t2==0)
                    {
                        ans+=abs(b-tree[t1].key);
                        del(root,tree[t1].key);
                        ans%=MOD;
                    }
                    else
                    {
                        if(abs(b-tree[t1].key)<=abs(tree[t2].key-b)  )
                        {
                            ans+=abs(b-tree[t1].key);
                            del(root,tree[t1].key);
                            ans%=MOD;
                        }
                        else
                        {
                            ans+=abs(tree[t2].key-b);
                            del(root,tree[t2].key);
                            ans%=MOD;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}