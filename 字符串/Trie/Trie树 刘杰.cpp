#include<bits/stdc++.h>
using namespace std;
struct trie
{
    map<char,trie>Data;
    void insert(char s[]){
        if(!s[0])  return;
        Data[s[0]].insert(s+1);
    }
};
char s[100005];
int dfs(trie &T)
{
    if(!T.Data.size())  return 0;
    int flag=0;
    for(map<char,trie>::iterator it=T.Data.begin();it!=T.Data.end();it++)
        flag|=1<<dfs((*it).second);
    if((flag&8)==8)  return 2;
    if((flag&3)==3)  return 2;
    if((flag&2)==2)  return 0;
    if((flag&1)==1)  return 1;
    return 3;
}
int main()
{
//    freopen("b.txt","r",stdin);
    int n,m,i;
    while(scanf("%d%d",&n,&m)!=EOF){
        trie T;
        for(i=0;i<n;i++){
            scanf("%s",s);
            T.insert(s);
        }
        int ans=dfs(T);
        if(ans==2||ans==1&&(m&1))  printf("First\n");
        else  printf("Second\n");
    }
    return 0;
}