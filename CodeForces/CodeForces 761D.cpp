#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f

int a[MAXN],b[MAXN],c[MAXN];
int n,l,r;

int main()
{

    scanf("%d%d%d", &n, &l, &r);
    for(int i=1; i<=n; i++)
        scanf("%d",a+i);
    for(int i=1; i<=n; i++)
        scanf("%d",c+i);
    int Min=INF,Max=0;
    for(int i=1; i<=n; i++)
    {
        Min=min(Min,a[i]+c[i]);
        Max=max(Max,a[i]+c[i]);
    }
    if(r-l<Max-Min)
        puts("-1");
    else
    {
        for(int i=1; i<=n; i++)
            b[i]=a[i]+c[i]-(Max-r);
        for(int i=1; i<n; i++)
            printf("%d ",b[i]);
        printf("%d\n",b[n]);
    }
    return 0;
}
