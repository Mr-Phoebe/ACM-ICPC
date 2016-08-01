#include<iostream>
#include<cstdlib>

using namespace std;

struct price
{
	int cost;
	int up;
}numprice[1000];

int comp ( const void *_a, const void *_b )
{
	struct price* a = (struct price*)_a;
	struct price* b = (struct price*)_b;	
    return (*a).cost-(*b).cost;
}

int main()
{
	int i,n,m,num=0,sum=0,min;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>numprice[i].cost>>numprice[i].up;

	while(num<m)
	{
		qsort(numprice,n,sizeof(struct price),comp);
		sum+=numprice[0].cost;
		numprice[0].cost+=numprice[0].up;
		num++;
	}
	cout<<sum<<endl;
	
} 