#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int a[MAXN];

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int ans=-1;
    for(int i=1; i<=n; i++)
    {
        if(a[i]>0 && k>=a[i])
        {
            if(ans==-1 || abs(m-i)*10<ans)
                ans=abs(m-i)*10;
        }
    }
    printf("%d\n",ans);
    return 0;
}
