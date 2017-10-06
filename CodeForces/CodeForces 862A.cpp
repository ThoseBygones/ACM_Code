#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int cnt[MAXN];

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1; i<=n; i++)
    {
        int temp;
        scanf("%d",&temp);
        cnt[temp]++;
    }
    int ans=0;
    for(int i=x-1; i>=0; i--)
    {
        if(!cnt[i])
            ans++;
    }
    if(cnt[x])
        ans+=cnt[x];
    printf("%d\n",ans);
    return 0;
}
