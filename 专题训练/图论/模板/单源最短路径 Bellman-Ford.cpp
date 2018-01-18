#include <iostream>
using namespace std;
const int maxnum = 100;
const int maxint = 1<<30;
 
// �ߣ�
typedef struct Edge{
	int u, v;    // ��㣬�ص�
	int weight;  // �ߵ�Ȩֵ
}Edge;
 
Edge edge[maxnum];     // ����ߵ�ֵ
int  dist[maxnum];     // ��㵽Դ����С����
 
int nodenum, edgenum, source;    // �������������Դ��
 
// ��ʼ��ͼ
void init()
{
	// ����������������Դ��
	cin >> nodenum >> edgenum >> source;
	for(int i=1; i<=nodenum; ++i)
		dist[i] = maxint;
	dist[source] = 0;
	for(int i=1; i<=edgenum; ++i)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].weight;
		if(edge[i].u == source)          //ע���������ó�ʼ���
			dist[edge[i].v] = edge[i].weight;
	}
}
 
// �ɳڼ���
void relax(int u, int v, int weight)
{
	if(dist[v] > dist[u] + weight)
		dist[v] = dist[u] + weight;
}
 
bool Bellman_Ford()
{
	for(int i=1; i<=nodenum-1; ++i)
		for(int j=1; j<=edgenum; ++j)
			relax(edge[j].u, edge[j].v, edge[j].weight);
	bool flag = 1;
	// �ж��Ƿ��и���·
	for(int i=1; i<=edgenum; ++i)
		if(dist[edge[i].v] > dist[edge[i].u] + edge[i].weight)
		{
			flag = 0;
			break;
		}
	return flag;
}
int main()
{
	//freopen("input3.txt", "r", stdin);
    init();
	if(Bellman_Ford())
		for(int i = 1 ;i <= nodenum; i++)
			cout << dist[i] << endl;
	return 0;
}