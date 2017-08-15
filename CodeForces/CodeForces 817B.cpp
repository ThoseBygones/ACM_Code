#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

map <LL,LL> mp;

LL a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&a[i]);
        mp[a[i]]++;
    }
    sort(a,a+n);
    if(a[1]!=a[2])
        printf("%I64d\n",mp[a[2]]);
    else if(a[1]==a[2] && a[0]!=a[1])
        printf("%I64d\n",(mp[a[2]]-1)*mp[a[2]]/2);
    else
        printf("%I64d\n",(mp[a[0]]-2)*(mp[a[0]]-1)*mp[a[0]]/6);
    return 0;
}
