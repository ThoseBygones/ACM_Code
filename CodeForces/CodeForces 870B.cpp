#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define INF 0x3fffffff

int a[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int ans;
    if(k==1)
    {
        ans=INF;
        for(int i=0; i<n; i++)
            ans=min(ans,a[i]);
    }
    else if(k==2)
        ans=max(a[0],a[n-1]);
    else
    {
        ans=-INF;
        for(int i=0; i<n; i++)
            ans=max(ans,a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
