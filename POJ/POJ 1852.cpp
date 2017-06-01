#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000005

int a[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,n;
        scanf("%d%d",&l,&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        int Min=0,Max=0;
        for(int i=1; i<=n; i++)
        {
            Min=max(Min,min(a[i],l-a[i]));
            Max=max(Max,max(a[i],l-a[i]));
        }
        printf("%d %d\n",Min,Max);
    }
    return 0;
}
