#include <cstdio>

const long long MAX = 1000000100;
const long long N = 1000000000;
const long long BASE = 40000;
bool used[MAX];

int main(void)
{
	freopen("out.txt","w",stdout);
    int cnt = 0;
    for(long long i = 2; i <= N; ++i){
        if(!used[i]){
            cnt++;
            for(long long j = i *i; j <= N; j += i)
                used[j] = true;
        }
        if(i % BASE == 0)
            printf("%d,",cnt);
    }
    return 0;
}
