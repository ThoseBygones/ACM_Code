#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int x=m/2;
    int ans=x*n;
    if(m%2)
        ans+=n/2;
    printf("%d\n",ans);
    return 0;
}
