#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

struct Sofa
{
    int x1,x2,y1,y2;
} s[MAXN];

int xl[MAXN],xr[MAXN];
int yl[MAXN],yr[MAXN];

int main()
{
    int d,n,m;
    scanf("%d%d%d",&d,&n,&m);
    for(int i=1; i<=d; i++)
    {
        scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
        xl[min(s[i].x1,s[i].x2)]++;
        yl[min(s[i].y1,s[i].y2)]++;
        xr[max(s[i].x1,s[i].x2)]++;
        yr[max(s[i].y1,s[i].y2)]++;
    }

    int cntl,cntr,cntt,cntb;
    scanf("%d%d%d%d",&cntl,&cntr,&cntt,&cntb);
    //利用前缀和
    for(int i=1; i<=n; i++)
        xl[i]+=xl[i-1];
    for(int i=1; i<=m; i++)
        yl[i]+=yl[i-1];
    for(int i=n; i>=1; i--)
        xr[i]+=xr[i+1];
    for(int i=m; i>=1; i--)
        yr[i]+=yr[i+1];
    for(int i=1; i<=d; i++)
    {
        int l=xl[max(s[i].x1,s[i].x2)-1];
        int r=xr[min(s[i].x1,s[i].x2)+1];
        int t=yl[max(s[i].y1,s[i].y2)-1];
        int b=yr[min(s[i].y1,s[i].y2)+1];
        if(s[i].x1!=s[i].x2)
        {
            l--;
            r--;
        }
        if(s[i].y1!=s[i].y2)
        {
            t--;
            b--;
        }
        if(cntl==l && cntr==r && cntt==t && cntb==b)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
