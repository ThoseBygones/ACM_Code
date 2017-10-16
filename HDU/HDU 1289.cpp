#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    float x;    //给的是32-bit的浮点数，用double会WA
    while(~scanf("%f",&x))
    {
        int cnt=0;
        while(fabs(x)>=2.0)
        {
            x/=2.0;
            cnt++;
        }
        while(fabs(x)<1.0)
        {
            x*=2.0;
            cnt--;
        }
        printf("%d %.6f\n",cnt,x);
    }
    return 0;
}
