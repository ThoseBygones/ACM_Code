#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 55

int a[MAXN],b[MAXN],c[MAXN];

int main()
{
    int n,sum,ans;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=1; i<n; i++)
        {
            scanf("%d",a+i);
            a[i]=a[i]+a[i-1];
        }
        for(int i=0; i<n-1; i++)
            scanf("%d",b+i);
        for(int i=n-2; i>=0; i--)
            b[i]=b[i+1]+b[i];
        for(int i=0; i<n; i++)
            scanf("%d",c+i);
        ans=INF;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                sum=a[i]+b[i]+c[i]+a[j]+b[j]+c[j];
                ans=min(sum,ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
