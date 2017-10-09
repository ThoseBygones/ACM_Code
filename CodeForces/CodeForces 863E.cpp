#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

struct TV
{
    int l,r;
    int id;
} a[MAXN];

bool cmp(TV x,TV y)
{
    if(x.l==y.l)
        return x.r<y.r;
    return x.l<y.l;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].id=i+1;
    }
    sort(a,a+n,cmp);
    int ans=-1;
    for(int i=1; i<n; i++)
    {
        if(a[i-1].r>=a[i].r)
        {
            ans=a[i].id;
            break;
        }
        else if(a[i-1].l>=a[i].l)
        {
            ans=a[i-1].id;
            break;
        }
        a[i].l=max(a[i].l,a[i-1].r+1);
    }
    printf("%d\n",ans);
    return 0;
}
