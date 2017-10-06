#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    LL l,r,x,y,k;
    scanf("%I64d%I64d%I64d%I64d%I64d",&l,&r,&x,&y,&k);
    if(l>r)
        swap(l,r);
    if(x>y)
        swap(x,y);
    for(LL i=x; i<=y; i++)
    {
        LL temp=i*k;
        if(temp>=l && temp<=r)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
