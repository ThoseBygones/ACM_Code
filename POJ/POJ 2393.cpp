#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005
#define LL long long

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int p=5000; //取最大值
    LL ans=0;
    int c,y;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&c,&y);
        p=min(c,p+s);
        ans+=p*y;
    }
    printf("%lld\n",ans);
    return 0;
}
