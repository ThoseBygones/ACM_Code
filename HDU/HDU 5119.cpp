#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
using namespace std;

#define MAXN 1<<20
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define LL long long
#define PII pair
#define MP make_pair
#define PB push_back

int a[MAXN];
LL dp[45][MAXN];   //dp[i][j]表示前i个数选择某些异或值为j的方法数

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<MAXN; j++)
                dp[i][j]=dp[i-1][j]+dp[i-1][j^a[i]];
        }
        LL ans=0;
        for(int i=m; i<MAXN; i++)
            ans+=dp[n][i];
        printf("Case #%d: %I64d\n",kase++,ans);
    }
    return 0;
}
