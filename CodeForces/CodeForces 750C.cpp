#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 1e9
#define MAXN 200005

int c[MAXN],d[MAXN];
int n;

bool check(int x)
{
    for(int i=1; i<=n; i++)
    {
        if(d[i]==1 && x<1900)
            return true;    //rating偏小
        if(d[i]==2 && x>=1900)
            return false;   //rating偏大
        x+=c[i];
    }
    return true;    //否则继续尝试大的值
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d",c+i,d+i);
    int l=-INF,r=INF;
    int mid;
    int ans=-INF-7;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    if(ans>=INF)
        puts("Infinity");
    else
    {
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            if((d[i]==1 && ans<1900) || (d[i]==2 && ans>=1900))
            {
                flag=false;
                break;
            }
            ans+=c[i];
        }
        if(!flag)
            puts("Impossible");
        else
            printf("%d\n",ans);
    }
    return 0;
}
