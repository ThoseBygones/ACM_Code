#include <bits/stdc++.h>
using namespace std;

#define MAXN 10005

int a[MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    while(m--)
    {
        int cnt=0;
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        for(int i=l; i<=r; i++)
        {
            if(a[i]<a[x])
                cnt++;
        }
        if(cnt==x-l)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
