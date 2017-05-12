#include<cstdio>
using namespace std;

int main()
{
    double l,p,q;
    while(scanf("%lf",&l)!=EOF)
    {
        scanf("%lf %lf",&p,&q);
        double t=l/(p+q);
        double x=t*p;
        printf("%lf\n",x);
    }
    return 0;
}
