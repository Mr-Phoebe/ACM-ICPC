#include <cstdio>
#include <cstdlib>
#include <cmath>

const double casenum = 16;
const double eps = 1e-6;
const double ans[] = {2.00000000, 3.00000000, 4.47213595, 214387610.46977758, 224604213.10457891, 193806038.84969449, 254370421.35367855, 158743182.54747945, 201557666.94907928, 228393439.55896023, 153667982.05712208, 167438398.19517651, 262710277.89617154, 275437586.73818922, 271691214.36530066, 307585813.38912231};

void assert(bool v)
{
	if (!v)
	{
		printf("WA\n");
		exit(0);
	}
}

int main(int argc, char* argv[])
{
	double x;
	for (int i=0; i<casenum; i++)
	{
		assert(scanf("%lf", &x) == 1);
		if (fabs(x - ans[i]) < eps || fabs(ans[i]) > eps && fabs((x - ans[i]) / ans[i]) < eps) continue;
		else
		{
			printf("WA\n");
			return 0;
		}
	}
	printf("AC!\n");
	return 0;
}
