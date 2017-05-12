#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL a[100005];
map <LL,LL> mp;

int main()
{
    LL n,x;
    scanf("%I64d%I64d",&n,&x);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        mp[a[i]]++;
    }
    LL ans=0;
    for(int i=1; i<=n; i++)
    {
        LL temp=a[i]^x;
        if(temp!=a[i])
            ans+=mp[temp];
        else
            ans+=mp[temp]-1;
    }
    printf("%I64d\n",ans/2);
    return 0;
}
