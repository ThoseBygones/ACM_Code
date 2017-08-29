#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define LL long long

double a[MAXN];
double sum[MAXN];  //前缀和

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%lf",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    double ans=0.0;
    for(int i=k; i<=n; i++)
        ans+=sum[i]-sum[i-k];
    ans/=(n-k+1);
    printf("%.10f\n",ans);
    return 0;
}
