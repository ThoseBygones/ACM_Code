#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int n=min(a,b);
    int ans=1;
    for(int i=1; i<=n; i++)
        ans*=i;
    printf("%d\n",ans);
    return 0;
}
