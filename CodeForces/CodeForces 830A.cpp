#include <bits/stdc++.h>
using namespace std;

#define INF 0x7fffffff

int a[1005],b[2005];

//两种情况：
//要么办公室钥匙人三点一线（这样只要人的位置与钥匙的位置按照坐标有序且一一对应，最大路径最小
//要么人拿完钥匙要折回去办公室（这样的话考虑钥匙尽量离人（或办公室近），仍然满足以上结论）

int main()
{
    int n,k,p;
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=k; i++)
        scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+k+1);
    int ans=INF;
    for(int i=0; i<=k-n; i++)
    {
        int Max=0;
        for(int j=1; j<=n; j++) //可以证明，人的位置与钥匙的位置按照坐标有序且一一对应时，最大路径最小
            Max=max(Max,abs(a[j]-b[i+j])+abs(b[i+j]-p));
        ans=min(Max,ans);
    }
    printf("%d\n",ans);
    return 0;
}
