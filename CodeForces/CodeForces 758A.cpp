#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    int Max=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        Max=max(Max,a[i]);
    }
    int ans=0;
    for(int i=1; i<=n; i++)
        ans+=Max-a[i];
    printf("%d\n",ans);
    return 0;
}
