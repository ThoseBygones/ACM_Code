#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int a[MAXN];
int l[MAXN];
int r[MAXN];

int main()
{
    int n,m;
    scanf("%d",&n);
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
        scanf("%d%d",&l[i],&r[i]);
    if(sum>r[m])
    {
        puts("-1");
        return 0;
    }
    for(int i=1; i<=m; i++)
    {
        if(sum<l[i])
        {
            printf("%d",l[i]);
            return 0;
        }
        else if(sum>=l[i] && sum<=r[i])
        {
            printf("%d\n",sum);
            return 0;
        }
    }
    return 0;
}
