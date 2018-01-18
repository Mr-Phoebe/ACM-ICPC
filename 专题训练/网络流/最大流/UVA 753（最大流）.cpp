#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 550
#define MAXM 50010
int N,M,K,CNT,edgenum,s,t,first[MAXN];
struct edge
{
    int u,v,f,cap,next;
}e[MAXM];
struct  device  //����
{
    char s1[30],s2[30];
}d[MAXN];
struct adapter //ת����
{
    char s1[30], s2[30];
}a[MAXN];
struct receptacle  //����
{
    char s[30];
}r[MAXN]; 


void printfff()  //���Դ�ӡ����
{
    printf("M=%d  N=%d   K=%d  CNT=%d  s=%d   t=%d\n",M,N,K,CNT,s,t);
    for(int i=0; i<edgenum; i++)
        printf("%d:  %d-->%d=%d %d\n",i,e[i].u,e[i].v,e[i].cap,e[i].next);
}
void add(int u  ,int v , int cap)
{
    int t;
    e[edgenum].u=u; e[edgenum].v=v;
    e[edgenum].f=0; e[edgenum].cap=cap;
    e[edgenum].next=first[u];
    first[u]=edgenum++;

    t=u; u=v; v=t;

    e[edgenum].u=u; e[edgenum].v=v;
    e[edgenum].f=0; e[edgenum].cap=0;
    e[edgenum].next=first[u];
    first[u]=edgenum++;
}
void input()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
        scanf("%s",r[i].s);

    scanf("%d",&M);
    for(int i=1; i<=M; i++)
        scanf("%s%s",d[i].s1,d[i].s2);

    scanf("%d",&K);
    for(int i=1; i<=K; i++)
        scanf("%s%s",a[i].s1,a[i].s2); 

    CNT=N+M+K;
}
void init()
{
    memset(first,-1,sizeof(first));
    edgenum=0;
    s=0;  t=CNT+1; //Դ��,���
    for(int i=1; i<=M; i++)  //���е���
    {
        add(s,i,1);  //Դ��͵�����������Ϊ1
        
        for(int j=1; j<=K ; j++) //���е�����ת����������
            if(!strcmp(d[i].s2 , a[j].s1)) //�������Բ���ת������
                add(i,j+M,INF);

        for(int j=1; j<=N; j++)  //�����Ͳ���ֱ������
            if(!strcmp(d[i].s2 , r[j].s))
                add(i,M+K+j,1);
    }

    for(int i=1; i<=K; i++) 
    {
        for(int j=1; j<=K; j++) //����ת������ת����֮�������
            if(i!=j && !strcmp(a[i].s2 , a[j].s1))  
                //���ÿ�����ͬ�����ת���������ӣ���Ϊû������
                add(i+M,j+M,INF);

        for(int j=1; j<=N; j++) //����ת���������в�������
            if(!strcmp(a[i].s2 , r[j].s)) //ת�����ɲ��������
                add(i+M , M+K+j , INF);  //ת�����Ͳ�������
    }

    for(int i=1; i<=N; i++)  //�����ͻ������
        add(M+K+i,t,1);
}
void EK()
{
    queue<int>q;
    int a[MAXN],path[MAXN];
    int F;
    F=0;
    while(1)
    {
        memset(path,-1,sizeof(path));
        memset(a,0,sizeof(a));
        a[s]=INF;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front(); q.pop();
            for(int k=first[u]; k!=-1; k=e[k].next)
            {
                int v=e[k].v;
                if(!a[v] && e[k].f<e[k].cap)
                {
                    a[v]=a[u]<e[k].cap-e[k].f?a[u]:e[k].cap-e[k].f;
                    path[v]=k;
                    q.push(v);
                }
            }
        }

        if(!a[t]) break;

        for(int k=path[t]; k!=-1; k=path[e[k].u]) //����
        {
            //printf("%d<--%d ",e[k].v,e[k].u);
            e[k].f+=a[t];
            e[k^1].f-=a[t];
        }
        //printf("\n");
        F+=a[t];
    }

    //printf("F=%d\n",F);
    printf("%d\n",M-F);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        init();
        //printfff();
        EK();
        if(T) printf("\n");
    }
    return 0;
}