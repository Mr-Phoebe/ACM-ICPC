//hdu1166  简单线段树
#include <iostream>
using namespace std;
#define maxn 500004
struct node
{
	int left,right;
	int num;
};
node tree[3*maxn];
int out=0;
void build(int left,int right,int i)
{
	tree[i].left =left;
	tree[i].right =right;
	tree[i].num =0;
	if(tree[i].left ==tree[i].right )
		return ;
	build(left,(left+right)/2,2*i);
	build((left+right)/2+1,right,2*i+1);
}
void insert(int id,int i,int j)//i营地增加j个人
{
	if(tree[id].left<=i&&tree[id].right >=i)
		tree[id].num +=j;
	if(tree[id].left ==tree[id].right )
		return;
	if(i>tree[id].right )
		return;
	if(i<tree[id].left )
		return;
	int mid=(tree[id].left +tree[id].right )/2;
	if(i<=mid)
		insert(id*2,i,j);
	else
		insert(id*2+1,i,j);
}
void sum(int id,int i,int j)//在id点处加i到j的数
{
	int mid=(tree[id].left +tree[id].right )/2;
	if(tree[id].left ==i&&tree[id].right ==j)
	{
		out+=tree[id].num ;
		return;
	}
	if(j<=mid)
		sum(2*id,i,j);
	else if(i>mid)
		sum(2*id+1,i,j);
	else
	{
		sum(2*id,i,mid);
		sum(2*id+1,mid+1,j);
	}

}
int main()
{
	int t,n,num,l,r,Case=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case %d:\n",Case++);
		scanf("%d",&n);
		build(1,n,1);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num);
			insert(1,i,num);
		}
		char ss[20];
		while(scanf("%s",ss))
		{
			if(ss[0]=='E')
				break;
			if(ss[0]=='Q')
			{
				scanf("%d%d",&l,&r);
				sum(1,l,r);
				printf("%d\n",out);
				out=0;
			}
			if(ss[0]=='A')
			{
				scanf("%d%d",&l,&r);
				insert(1,l,r);
			}
			if(ss[0]=='S')
			{
				scanf("%d%d",&l,&r);
				insert(1,l,-r);
			}

		}

	}
	return 0;
}