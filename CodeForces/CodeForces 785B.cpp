#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 200005
#define INF 1e9+7

int n,m;
int al[MAXN],ar[MAXN];
int bl[MAXN],br[MAXN];

int main()
{
    while(~scanf("%d",&n))
    {
        int amax=0,amin=INF;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",al+i,ar+i);
            amax=max(al[i],amax);
            amin=min(ar[i],amin);
        }
        scanf("%d",&m);
        int bmax=0,bmin=INF;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",bl+i,br+i);
            bmax=max(bl[i],bmax);
            bmin=min(br[i],bmin);
        }
        int x,y;
        if(amin<bmax)
            x=bmax-amin;
        else
            x=0;
        if(bmin<amax)
            y=amax-bmin;
        else
            y=0;
        int ans=max(x,y);
        printf("%d\n",ans);
    }
    return 0;
}
