#include<iostream>
using namespace std;

struct node
{
	int x,y;
}s1,s2;

int a[4][4],b[4][4],fac[10],g[10],stepv1[362881],stepv2[362881],step1[40000],step2[40000],q1[40000][4][4],q2[40000][4][4];
bool vis1[362881],vis2[362881];
int flag,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};

bool ok(int x,int y)
{
	if((x>=1)&&(y>=1)&&(x<=3)&&(y<=3))
		return true;
	return false;
}

void make()
{
	int i;
	fac[0]=1;
	for(i=1;i<=9;i++)fac[i]=fac[i-1]*i;
}

int gcc(int f[][4])
{
	int p,ans,i,j,k;
	
	p=8;ans=0;
	for(i=0;i<=8;i++)g[i]=i;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
		{
			ans+=g[f[i][j]]*fac[p];
			for(k=f[i][j]+1;k<=8;k++)g[k]--;
			p--;
		}
	return ans;
}

node findd(int f[][4])
{
	int i,j;node t;
	
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			if(f[i][j]==0)
			{
				t.x=i;t.y=j;return t;
			}
}

void bfs()
{
	int i,j,k,d,front1,rear1,front2,rear2,x,y;
	
	front1=rear1=0;rear1=(rear1+1)%30000;vis1[gcc(a)]=1;
	step1[rear1]=0;stepv1[gcc(a)]=step1[rear1];
	front2=rear2=0;rear2=(rear2+1)%30000;vis2[gcc(b)]=1;
	step2[rear2]=0;stepv2[gcc(b)]=step2[rear2];
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)q1[rear1][i][j]=a[i][j];
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)q2[rear2][i][j]=b[i][j];
	/*for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
			cout<<b[i][j];
		cout<<endl;
	}*/
		
	while((front1!=rear1)||(front2!=rear2))
	{
		front1=(front1+1)%30000;s1=findd(q1[front1]);
		front2=(front2+1)%30000;s2=findd(q2[front2]);
		//cout<<"s1.x="<<s1.x<<"s1.y="<<s1.y<<endl;
		//cout<<"s2.x="<<s2.x<<"s2.y="<<s2.y<<endl;
		for(d=0;d<=3;d++)
		{
			x=s1.x+dx[d];y=s1.y+dy[d];
			if(ok(x,y))
			{
				for(i=1;i<=3;i++)
					for(j=1;j<=3;j++)a[i][j]=q1[front1][i][j];
				swap(a[x][y],a[s1.x][s1.y]);
				k=gcc(a);
				if(!vis1[k])
				{
					rear1=(rear1+1)%30000;vis1[k]=1;
					step1[rear1]=step1[front1]+1;stepv1[k]=step1[rear1];
					for(i=1;i<=3;i++)
						for(j=1;j<=3;j++)q1[rear1][i][j]=a[i][j];
					if(vis2[k])
					{
						cout<<stepv1[k]+stepv2[k]<<endl;flag=0;return;
					}
				}
			}
			x=s2.x+dx[d];y=s2.y+dy[d];
			if(ok(x,y))
			{
				for(i=1;i<=3;i++)
					for(j=1;j<=3;j++)b[i][j]=q2[front2][i][j];
				swap(b[x][y],b[s2.x][s2.y]);
				k=gcc(b);
				if(!vis2[k])
				{
					rear2=(rear2+1)%30000;vis2[k]=1;
					step2[rear2]=step2[front2]+1;stepv2[k]=step2[rear2];
					for(i=1;i<=3;i++)
						for(j=1;j<=3;j++)q2[rear2][i][j]=b[i][j];
					if(vis1[k])
					{
						cout<<stepv1[k]+stepv2[k]<<endl;flag=0;return;
					}
				}
			}
		}
	}
}

int main()
{
	int i,j;
	
	freopen("in.txt","r",stdin);
	flag=1;make();
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)cin>>a[i][j];
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)b[i][j]=3*(i-1)+j-1;
	//cout<<gcc(a)<<endl;	
	if(gcc(a)==gcc(b))
	{
		cout<<0<<endl;flag=0;return 0;
	}
	bfs();
	if(flag==1)cout<<-1<<endl;
	
	return 0;
}
