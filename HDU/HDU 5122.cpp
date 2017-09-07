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

#define MAXN 1000005
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define LL long long
#define PII pair
#define MP make_pair
#define PB push_back

int a[MAXN];

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        int cnt=0;
        int Max=a[n];
        for(int i=n; i>=1; i--)
        {
            if(a[i]>Max)
                cnt++;
            Max=min(Max,a[i]);
        }
        printf("Case #%d: %d\n",kase++,cnt);
    }
    return 0;
}
