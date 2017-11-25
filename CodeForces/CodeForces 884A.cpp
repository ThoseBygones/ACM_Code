#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int a[MAXN];

int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        t-=86400-a[i];
        cnt++;
        if(t<=0)
        {
            printf("%d\n",cnt);
            break;
        }
    }
    return 0;
}
