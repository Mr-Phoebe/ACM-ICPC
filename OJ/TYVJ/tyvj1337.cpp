#include<cstdio>

#include<algorithm> 

#define sf scanf

#define pf printf

#define ps for(;;)

#define lp(i,a,b) for(int i=a;i<=b;++i)

using namespace std;

struct mat
{
    mat()
	{
		lp(i,0,1)
        lp(j,0,1)
        data[i][j]=0;
    }
    int data[2][2];

};

mat operator*(mat a,mat b){
    mat t;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            for(int k=0;k<2;++k)
			{
                t.data[i][j]+=a.data[i][k]*b.data[k][j];
                t.data[i][j]%=32768;
            }
    return t;
}

mat pmod(mat a,int b)
{
    if(b==1)return a;
    else
	{
        mat t=pmod(a,b/2);
        t=t*t;
        if(b&1)t=t*a;
        return t;
    }

}

int main()
{
    int n;sf("%d",&n); 
    mat t;
    t.data[0][0]=0;
    t.data[0][1]=1;
    t.data[1][0]=1;
    t.data[1][1]=1;
    t=pmod(t,n);
    pf("%d\n",t.data[0][1]);
    //ps;
    return 0;

}
