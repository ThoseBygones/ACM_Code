#include <bits/stdc++.h>
using namespace std;

#define MAXN 505
#define MAXT 1000000000

struct Pixel
{
    int x,y,t;
} p[MAXN*MAXN];

int n,m,k,q;
int sum[MAXN][MAXN];    //前缀和

bool check(int val)
{
    memset(sum,0,sizeof(sum));
    for(int i=0; i<q; i++)
    {
        if(p[i].t<=val)
            sum[p[i].x][p[i].y]=1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            if(i>=k && j>=k && sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]==k*k)    //行列连续的broken pixels都>=k且broken pixels的区域为k*k的正方形
                return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=0; i<q; i++)
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].t);
    int l=-1,r=MAXT+1;
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}


