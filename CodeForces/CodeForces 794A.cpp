#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int a[MAXN];

int main()
{
    int cur,b,c,n;
    scanf("%d%d%d",&cur,&b,&c);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]>b && a[i]<c)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
