#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
const double eps = 1e-8;
const double r = 0.99;	//降温速度
const int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
const int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
double a, b, c, d, e, f;

double dis(double x, double y, double z)
{
    return sqrt(x * x + y * y + z * z);
}

//已知x,y,求z
double getz(double x, double y)
{
    double A = c, B = e * x + d * y,
           C = a * x * x + b * y * y + f * x * y - 1;
    double delta = B * B - 4 * A * C;
    if (delta < 0) return 1e60;
    double z1 = (-B + sqrt(delta)) / 2 / A,
           z2 = (-B - sqrt(delta)) / 2 / A;
    if (z1 * z1 < z2 * z2) return z1;
    else return z2;
}

double solve()
{
    //模拟退火
    double step = 1;	//步长
    double x = 0, y = 0, z;
    while (step > eps)
    {
        z = getz(x, y);
        for (int i = 0; i < 8; i++)
        {
            double nx = x + dx[i] * step,
                   ny = y + dy[i] * step,
                   nz = getz(nx, ny);
            if (nz > 1e30) continue;
            if (dis(nx, ny, nz) < dis(x, y, z))
            {
                x = nx;
                y = ny;
                z = nz;
            }
        }
        step *= r;
    }
    return dis(x, y, z);
}

int main()
{
    while (scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f) != EOF)
    {
        printf("%.8f\n", solve());
    }
    return 0;
}
