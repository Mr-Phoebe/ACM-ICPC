#include<cstdio>
#include<cstring>

char tmp[1000010], ans[1000010], temp[1000010];

int main()
{
    int p, x, a = 0, b = 0;
    scanf("%d%d", &p, &x);
    strcpy(ans, "Impossible");
    for(int i = 1; i <= 9; i++)
	{
        a = 0, b = i;
        for(int j = 0; j < p; j++)
		{
            tmp[j] = b + '0';
            a = a + b * x;
			b = a % 10, a /= 10;
        }
        int len=strlen(tmp);
        for(int i=0;i<len;i++)
            temp[len-i-1]=tmp[i];
        temp[len]='\0';
        if(b == i && a == 0 && strcmp(ans, temp) > 0 && temp[0] != '0')
            strcpy(ans, temp);
    }
    puts(ans);
    return 0;
}
