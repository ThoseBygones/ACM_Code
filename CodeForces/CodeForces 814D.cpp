#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define PI acos(-1)
#define EPS 1e-10

struct Circle
{
    double x;
    double y;
    double r;
    int cnt;
    bool operator <(const Circle &a) const
    {
        return r>a.r;
    }
} c[MAXN];

bool judge(Circle a,Circle b)   //相离返回false，包含返回true
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<(a.r+b.r)*(a.r+b.r);
}

double getArea(Circle a)
{
    return PI*a.r*a.r;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
    sort(c,c+n);
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(judge(c[i],c[j]))
                c[j].cnt++;
        }
    }
    double ans=0.0;
    for(int i=0; i<n; i++)
    {
        if(!c[i].cnt)
            ans+=getArea(c[i]);
        else if(c[i].cnt&1)
            ans+=getArea(c[i]);
        else
            ans-=getArea(c[i]);
    }
    printf("%.8f\n",ans);
    return 0;
}
