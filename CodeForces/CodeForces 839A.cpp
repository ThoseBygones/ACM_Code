#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int a[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
    {
        if(a[i]<=8)
            k-=a[i];
        else
        {
            k-=8;
            a[i+1]+=(a[i]-8);
        }
        if(k<=0)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
