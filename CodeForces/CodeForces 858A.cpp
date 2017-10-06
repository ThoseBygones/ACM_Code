#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    int cnt2=0,cnt5=0;
    while(n%2==0 && cnt2<k)
    {
        n/=2;
        cnt2++;
    }
    while(n%5==0 && cnt5<k)
    {
        n/=5;
        cnt5++;
    }
    for(int i=1; i<=k; i++)
        n*=10;
    printf("%I64d\n",n);
    return 0;
}
