#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005

int a[MAXN];
int b[MAXN];

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=m; i++)
        scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int p1=1;
    int p2=1;
    while(p1<=n && p2<=m)
    {
        if(a[p1]<=b[p2])
        {
            p1++;
            p2++;
        }
        else
            p2++;
    }
    if(p1>n)
        puts("NO");
    else
        puts("YES");
    return 0;
}
