#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    bool flag=false;
    for(int i=1; i<=n-2; i++)
    {
        if(a[i]+a[i+1]>a[i+2])
        {
            flag=true;
            break;
        }
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
