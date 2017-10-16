//01分数规划+二分法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 1005
#define INF 1e9
#define EPS 1e-6

double a[MAXN],b[MAXN];
double d[MAXN];
int n,k;

double check(double val)
{
    double sum=0.0;
    for(int i=0; i<n; i++)
        d[i]=a[i]-b[i]*val;
    sort(d,d+n);
    for(int i=k; i<n; i++)
        sum+=d[i];
    return sum;
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==0 && k==0)
            break;
        for(int i=0; i<n; i++)
            scanf("%lf",&a[i]);
        for(int i=0; i<n; i++)
            scanf("%lf",&b[i]);
        double l=INF,r=-INF;
        for(int i=0; i<n; i++)
        {
            l=min(l,a[i]/b[i]);
            r=max(r,a[i]/b[i]);
        }
        while(r-l>EPS)
        {
            double mid=(l+r)/2;
            if(check(mid)>0)
                l=mid;
            else
                r=mid;
        }
        printf("%.0f\n",l*100);
    }
    return 0;
}


//01分数规划+Dinkelbach算法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 1005
#define EPS 1e-6

struct Node
{
    double a,b,d;
} p[MAXN];

int n,k;

bool cmp(const Node &x,const Node &y)
{
    return x.d<y.d;
}

double Dickelbach()
{
    double val;
    double ans=0;
    double x,y;
    while(true)
    {
        val=ans;
        for(int i=0; i<n; i++)
            p[i].d=p[i].a-p[i].b*val;
        sort(p,p+n,cmp);
        x=y=0;
        for(int i=k; i<n; i++)
        {
            x+=p[i].a;
            y+=p[i].b;
        }
        ans=x/y;
        if(fabs(val-ans)<EPS)
            return val;
    }
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==0 && k==0)
            break;
        for(int i=0; i<n; i++)
            scanf("%lf",&p[i].a);
        for(int i=0; i<n; i++)
            scanf("%lf",&p[i].b);
        printf("%.0f\n",100*Dickelbach());
    }
    return 0;
}
