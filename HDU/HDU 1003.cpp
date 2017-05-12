#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[100010],dp[100010];

int main()
{
    int T,n,mmax,kase=1;
    int p1,p2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        dp[1]=a[1];
        for(int i=2; i<=n; i++)
        {
            if(dp[i-1]<0)
                dp[i]=a[i];
            else
                dp[i]=dp[i-1]+a[i];
        }
        mmax=dp[1];
        p2=1;
        for(int i=2; i<=n; i++)
        {
            if(mmax<dp[i])
            {
                mmax=dp[i];
                p2=i;
            }
        }
        int tempsum=0;
        p1=p2;
        for(int i=p2; i>0; i--)
        {
            tempsum+=a[i];
            if(tempsum==mmax)
                p1=i;
        }
        printf("Case %d:\n",kase++);
        printf("%d %d %d\n",mmax,p1,p2);
        if(T)
            printf("\n");
    }
    return 0;
}
