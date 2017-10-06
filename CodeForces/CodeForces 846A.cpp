#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int a[MAXN];
int dp[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    fill(dp,dp+n,INF);
    for(int i=0; i<n; i++)
        *upper_bound(dp,dp+n,a[i])=a[i];
    printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    return 0;
}
