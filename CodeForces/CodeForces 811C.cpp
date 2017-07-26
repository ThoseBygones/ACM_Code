#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005

int a[MAXN];
int l[MAXN];
int r[MAXN];
int dp[MAXN];
int vis[MAXN];

int sum(int l,int r)
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=l; i<=r; i++)
    {
        if(!vis[a[i]])
        {
            vis[a[i]]=1;
            ans^=a[i];
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(!l[a[i]])
            l[a[i]]=i;
        r[a[i]]=i;
    }

    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1];
        if(r[a[i]]==i)
        {
            bool flag=true;
            int left=l[a[i]];
            for(int j=l[a[i]]; j<=r[a[i]]; j++)
            {
                if(r[a[j]]>i)
                    flag=false;
                left=min(left,l[a[j]]);
            }
            if(flag)
                dp[i]=max(dp[i],dp[left-1]+sum(left,i));
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
