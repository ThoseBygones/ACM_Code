#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 1005
#define INF 1e9+7

struct Section
{
    double l;
    double r;
} s[MAXN];

bool cmp(Section a,Section b)
{
    return a.r<b.r;
}

int main()
{
    int n,kase=1;
    double d;
    while(~scanf("%d%lf",&n,&d))
    {
        if(n==0 && d==0)
            break;
        bool flag=true;
        double x,y;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf",&x,&y);
            if(flag)
            {
                if(y>d)
                {
                    flag=false;
                    continue;
                }
            }
            s[i].l=x-sqrt(d*d-y*y);
            s[i].r=x+sqrt(d*d-y*y);
        }
        printf("Case %d: ",kase++);
        if(!flag)
        {
            printf("-1\n");
            continue;
        }
        sort(s,s+n,cmp);
        int cnt=0;
        double right=-INF;
        for(int i=0; i<n; i++)
        {
            if(right<s[i].l)
            {
                cnt++;
                right=s[i].r;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
