#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(n>=i)
        {
            n-=i;
            a[++cnt]=i;
        }
    }
    a[cnt]+=n;
    printf("%d\n",cnt);
    for(int i=1; i<=cnt; i++)
    {
        if(i!=cnt)
            printf("%d ",a[i]);
        else
            printf("%d\n",a[i]);
    }
    return 0;
}
