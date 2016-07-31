#include <iostream>
#include <cstdio>
using namespace std;

const int minScore[5] = {85, 80, 75, 70, 60};
const int maxScore[5] = {100, 84, 79, 74, 69};
const double GPA4[5] = {4.0, 3.5, 3.0, 2.5, 2.0};
int totalScore, numOfCourses;
int scale[5];

int main()
{
    int T;
//    freopen("data.in", "r", stdin);
//    freopen("data.std", "w", stdout);
    scanf("%d", &T);
    while (T--) 
    {
        scanf("%d %d", &totalScore, &numOfCourses);
        totalScore *= numOfCourses;
        double minGPA = 4.0, maxGPA = 0.0;
        for (scale[0] = 0; scale[0] <= numOfCourses; ++scale[0])    
            for (scale[1] = 0; scale[1] <= numOfCourses - scale[0]; ++scale[1])
                for (scale[2] = 0; scale[2] <= numOfCourses - scale[0] - scale[1]; ++scale[2])
                    for (scale[3] = 0; scale[3] <= numOfCourses - scale[0] - scale[1] - scale[2]; ++scale[3]) 
                    {
                        scale[4] = numOfCourses - scale[0] - scale[1] - scale[2] - scale[3];
                        int minValue = 0, maxValue = 0;
                        for (int i = 0; i < 5; ++i)
                        {
                            minValue += minScore[i] * scale[i];
                            maxValue += maxScore[i] * scale[i];
                        }
                        if (totalScore >= minValue && totalScore <= maxValue) 
                        {
                            double GPA = 0;
                            for (int i = 0; i < 5; ++i)
                                GPA += GPA4[i] * scale[i];
                            GPA /= numOfCourses;
                            minGPA = min(minGPA, GPA);
                            maxGPA = max(maxGPA, GPA);
//                          for (int i = 0; i < 5; ++i)
//                              printf("%d ", scale[i]);
//                          printf("%.2lf\n", GPA);
                        }
                    }
        printf("%.4lf %.4lf\n", minGPA, maxGPA);
    }
    return 0;
}