#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    int ans=-INF;
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int Min=a[1];
    for(int i=2; i<=n; i++)
    {
        ans=max(ans,a[i]-Min);  //先比较差值，避免与自身做差
        Min=min(Min,a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
