#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

int a[MAXN*2];
int dp[MAXN*2];   //dp[i] refers to the most cities xhd can visit from city 1 to city i

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            int w,l;
            scanf("%d%d",&w,&l);
            a[i+n]=a[i]=w-l;
            dp[i+n]=dp[i]=1;    //There is a bug here -- If I give all w-l<0 here, it will output a wrong answer 1
        }
        for(int i=2; i<=2*n; i++)
        {
            if(a[i]+a[i-1]>=0 && a[i-1]>=0)
            {
                a[i]=a[i]+a[i-1];
                dp[i]+=dp[i-1];
                if(dp[i]==n)
                    break;
            }
        }
        int Max=0;
        for(int i=1; i<=2*n; i++)
            Max=max(Max,dp[i]);
        printf("%d\n",Max);
    }
    return 0;
}
