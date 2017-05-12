#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define EPS 1e-8

double x,y,c;

bool ok(double width)
{
    double xx=sqrt(x*x-width*width);
    double yy=sqrt(y*y-width*width);
    double cc=(xx*yy)/(xx+yy);
    if(cc>c-EPS)
        return true;
    return false;
}

int main()
{
    double width;
    while(~scanf("%lf%lf%lf",&x,&y,&c))
    {
        //公式c/yy=x1/width;c/xx=y1/width;x1+y1=width -> c/yy+c/xx=1 -> c=(xx*yy)/(xx+yy)
        double left=0;
        double right=min(x,y);
        double mid;
        while(left+EPS<right)
        {
            mid=(left+right)/2;
            if(ok(mid))
                left=mid;
            else
                right=mid;
        }
        printf("%.3lf\n",mid);  //G++改为%.3f
    }
    return 0;
}
