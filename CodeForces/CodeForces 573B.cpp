#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005

int h[MAXN];    //块的高度
int l[MAXN];    //块根据左侧块高度需要多少次能破坏完
int r[MAXN];    //块根据右侧块高度需要多少次能破坏完
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",h+i);
    h[0]=h[n+1]=0;
    for(int i=1; i<=n; i++)
        l[i]=min(l[i-1]+1,h[i]);
    for(int i=n; i>=1; i--)
        r[i]=min(r[i+1]+1,h[i]);
    int ans=0;
    for(int i=1; i<=n; i++)
        ans=max(ans,min(l[i],r[i]));
    printf("%d\n",ans);
    return 0;
}
