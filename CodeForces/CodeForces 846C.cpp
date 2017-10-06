#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define LL long long
#define INF 0x3f3f3f3f
#define LINF 0x3fffffff3fffffff

LL a[MAXN];
LL sum[MAXN];   //prefix sum

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    LL ans=-INF;
    int d1,d2,d3;
    for(int i=0; i<=n; i++)
    {
        LL temp=sum[i];
        int j=i;
        for(int k=i; k<=n; k++)
        {
            if(sum[k]<temp) //if sum[k]>temp, why not let j==i? so only when sum[k]<temp we let j==k
            {
                j=k;
                temp=sum[k];
            }
            LL res=(sum[i]-sum[0])-(sum[j]-sum[i])+(sum[k]-sum[j])-(sum[n]-sum[k]);
            if(res>ans)
            {
                ans=res;
                d1=i;
                d2=j;
                d3=k;
            }
        }
    }
    printf("%d %d %d\n",d1,d2,d3);
    return 0;
}
