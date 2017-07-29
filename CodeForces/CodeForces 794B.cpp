#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

double hh[MAXN];

int main()
{
    int n,h;
    scanf("%d%d",&n,&h);
    hh[1]=1.0*h/sqrt((double)n);
    for(int i=2; i<n; i++)
        hh[i]=1.0*h*sqrt(1.0*i/n);
    for(int i=1; i<n; i++)
        printf("%.12f ",hh[i]);
    puts("");
    return 0;
}
