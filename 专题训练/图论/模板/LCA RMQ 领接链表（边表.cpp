#include<iostream>
#include<cmath>

using namespace std;

const int maxn = 10010;
int N,m,Q;
 
//Union and Find set
int p[maxn];
int Rank[maxn];         //depth
 
int Find_Set(int x)    
{
      if(x!=p[x])
         p[x]=Find_Set(p[x]);       
      return p[x];
}
 
void Union_Set(int u,int v)
{
	u=Find_Set(u);
	v=Find_Set(v);
	if(Rank[u]==Rank[v])
	{
		p[v]=u;
		Rank[u]++;
	}
	else if(Rank[u]<Rank[v])
		p[u]=v;
	else 
		p[v]=u;
}
 
 
///Graph
struct Edge           //�߱�
{
	int v;
	int len;
	Edge* link;
}buffer[maxn*2];
int tol;              //�߱�����
 
struct Node           //���
{
	int rlen;   //�������ý��ľ���
	Edge* link;
}node[maxn];

 
bool vis[maxn]={0};
int root=0;   //��������������
 
void Add_Edge(int u,int v,int w)    //(1)
{
	Edge* tmp=&buffer[tol++];
	tmp->v=v;
	tmp->len=w;
	tmp->link=node[u].link;         //���±�ͷ
	node[u].link=tmp;               //���±�ͷ��������
}
 
//Graph
 
 
//LCA DATA
int index[maxn*2]; //ŷ������
int dep[maxn*2];   //ŷ�����ж�Ӧ�����
int first[maxn];   //�������ŷ�����е�һ�γ��ֵ�ʱ�䣨�±�
int cnt;           //ŷ�����е�ȫ���±�
 
 
 
//DFS
 
void DFS(int u,int DEP,int rlen)     //O(N)  
{
	//Graph
	vis[u]=true;
	node[u].rlen=rlen;
	//LCA��ŷ�����еĸ���
	cnt++;
	index[cnt]=u;
	dep[cnt]=DEP;
	if(first[u]==0)
		first[u]=cnt;
	//DFS
	Edge* tmp=node[u].link;
	while(tmp)
	{
		if(vis[tmp->v]==false)
		{
			DFS(tmp->v , DEP+1, rlen+tmp->len);
			//LCA
			cnt++;
			index[cnt] = u;
			dep[cnt] = DEP;
		}
		tmp=tmp->link;
	}
}
 
 
//RMQ  ��dep���� RMQ
int dp[maxn*2][16];   //�����dep��������Сֵ���±�
 
void RMQ_PRE(int* dep,int n)        //nlogN
{
	for(int i=1; i<=n; i++)
		dp[i][0] = i;
	int m = log(double(n)) / log(2.0);
	for(int j=1; j<=m; j++)
		for(int i=1; i+(1<<j)-1 <= n; i++)
		{
			if(dep[ dp[i][j-1] ] <= dep[ dp[i+(1<<(j-1))][j-1] ] )
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = dp[i+(1<<(j-1))][j-1];
		}
}
 
 
inline int RMQ(int l,int r)   //����dep[l..r]������СֵԪ�ص��±�  O(1)
{
	int k=log(double(r-l+1))/log(2.0);
	
	if(dep[ dp[l][k] ] <= dep[ dp[r-(1<<k)+1][k] ] )
		return dp[l][k];
	else
		return dp[r-(1<<k)+1][k];
}
 
///rmq end
 
//LCA
inline int LCA(int u,int v)  //O(1)
{
	int i=first[u];
	int j=first[v];
	if(i<=j)
		return index[ RMQ(i,j) ];
	else
		return index[ RMQ(j,i) ];
}
 
//LCA END
 
 
 
int main()
{
         while(scanf("%d%d%d",&N,&m,&Q) != EOF)
         {
			 memset(node,0,sizeof(node));
			 memset(Rank,0,sizeof(Rank));
                   //UnionSet init
			 for(int i=0; i<=N; i++)
				 p[i] = i;
			 
			 tol=0;
			 int u,v,w;
			 for(int i=1; i<=m; i++)
			 {
				 scanf("%d%d%d",&u,&v,&w);
				 Add_Edge(u,v,w);		//����ͼ
				 Add_Edge(v,u,w);
				 Union_Set(u,v);
			 }
			 for(int i=1; i<=N; i++)
				 Find_Set(i);			//���鼯ѹ��·��
			 bool Hash[maxn]={0};
			 for(int i=1; i<=N; i++)
				 Hash[p[i]]=1;
			 for(int v=1; v<=N; v++)
				 if(Hash[v])
				 {
					 Add_Edge(root,v,0);
					 Add_Edge(v,root,0);
				 }
				 //LCA DFS
				 //Graph
			cnt=0; 
			memset(vis,0,sizeof(vis));
                  //LCA
            memset(first,0,sizeof(first));
			DFS(root,0,0);          
                   //RMQ PRE
            RMQ_PRE(dep,2*(N+1)-1);           //O(NlogN)
			int a,b,c;
			while(Q--)
			{
				scanf("%d%d",&a,&b);
				if(p[a] != p[b])              //û�����ӣ�����LCA(a,b)==0�����ڵ㣩
					printf("Not connected\n");
				else
				{
					c = LCA(a,b);
					printf("%d\n",node[a].rlen + node[b].rlen - 2*node[c].rlen);
				}
			}
		 }
		 return 0;
}
 