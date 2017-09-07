#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
using namespace std;

#define MAXN 1000005
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define LL long long
#define PII pair
#define MP make_pair
#define PB push_back

struct Point
{
    int t;
    int pos;
} a[MAXN];

bool cmp(Point a,Point b)
{
    return a.t<b.t;
}

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&a[i].t,&a[i].pos);
        sort(a+1,a+1+n,cmp);
        double ans=0.0;
        for(int i=1; i<n; i++)
            ans=max(ans,fabs((double)(a[i+1].pos-a[i].pos)/(double)(a[i+1].t-a[i].t)));
        printf("Case #%d: %.2f\n",kase++,ans);
    }
    return 0;
}
