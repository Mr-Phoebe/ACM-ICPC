#include<iostream>

using namespace std;

int yw[300],sx[300],yy[300],t[300],no[300];

void swap(int x,int y)
{
	int tot;
	tot=t[x];t[x]=t[y];t[y]=tot;
	tot=no[x];no[x]=no[y];no[y]=tot;
	tot=yw[x];yw[x]=yw[y];yw[y]=tot;
}

int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		no[i]=i+1;
		cin>>yw[i]>>sx[i]>>yy[i];
		t[i]=yw[i]+sx[i]+yy[i];
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(t[i]>t[j])
				swap(i,j);
			if(t[i]==t[j])
			{
				if(yw[i]>yw[j])
					swap(i,j);
       			if(yw[i]==yw[j])
				   if(no[i]<no[j])
				   		swap(i,j);
			} 
		}
	for(i=0;i<5;i++)
		cout<<no[i]<<" "<<t[i]<<endl;
}