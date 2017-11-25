#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

int a[MAXN];
int vis[MAXN];
int c[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    LL ans=0;
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        int p=i;
        while(!vis[p])
        {
            int temp=a[p];
            vis[p]=1;
            p=temp;
            cnt++;
        }
        c[i]=cnt;
        ans+=(LL)cnt*(LL)cnt;
    }
    sort(c+1,c+1+n);
    ans+=2LL*c[n]*c[n-1];
    printf("%I64d\n",ans);
    return 0;
}
