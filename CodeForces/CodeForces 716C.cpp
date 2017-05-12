#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        if(i==1)
            puts("2");
        else
        {
            LL ans=1LL*(i+1)*(i+1)*i-(i-1);
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
