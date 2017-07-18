#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 10005
#define EPS 1e-6

double cable[MAXN];
int n,k;

bool biSearch(double val)
{
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=(int)(cable[i]/val);
    if(sum>=k)
        return true;
    return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%lf",&cable[i]);
    double l=0.0,r=1e5;
    while(r-l>=EPS)
    {
        double mid=(l+r)/2.0;
        if(biSearch(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%.2f\n",floor(r*100)/100);
    return 0;
}
