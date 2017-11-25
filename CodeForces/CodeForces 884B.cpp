#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int a[MAXN];

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum==x-n+1)
        puts("YES");
    else
        puts("NO");
    return 0;
}
