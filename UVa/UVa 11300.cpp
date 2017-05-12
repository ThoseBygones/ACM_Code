#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define LL long long
#define MAXN 1000010
using namespace std;

LL a[MAXN],b[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        LL sum=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        LL avg=sum/n;
        b[0]=0;
        for(int i=1; i<n; i++)
            b[i]=avg-a[i]+b[i-1];
        sort(b,b+n);
        LL mid=b[n/2];
        LL ans=0;
        for(int i=0; i<n; i++)
            ans+=abs(mid-b[i]);
        cout << ans << endl;
    }
    return 0;
}
