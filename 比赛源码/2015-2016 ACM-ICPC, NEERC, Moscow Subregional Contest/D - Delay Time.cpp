#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

double h1,t1,h2,t2;

int main()
{
    scanf("%lf%lf%lf%lf",&h1,&t1,&h2,&t2);

    printf("%lf",(t2 * sqrt(h1) - t1 * sqrt(h2)) / (sqrt(h1) - sqrt(h2)));
    return 0;
}
