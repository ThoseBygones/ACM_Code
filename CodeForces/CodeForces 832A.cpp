#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    LL a=n/k;
    if(a&1)
        puts("YES");
    else
        puts("NO");
    return 0;
}
