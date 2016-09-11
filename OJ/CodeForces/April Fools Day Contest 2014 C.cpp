#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int main(){

    int A,B,C,D,E;

    cin>>A>>B>>C>>D>>E;

     C>>=1;
     D/=7;
     E>>=2;
     A= min(A,B);
     A= min(A,E);
     C= min(D,C);
     C= min(A,C);
     cout<<C<<endl;

    //cout<<res<<endl;

    return 0;

}
