#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 100005

int a[MAXN];
int sum[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1; i<=n/2; i++)
        sum[i]=a[i]+a[n-i+1];
    int Min=sum[1];
    for(int i=2; i<=n/2; i++)
        Min=min(Min,sum[i]);
    printf("%d\n",Min);
    return 0;
}
