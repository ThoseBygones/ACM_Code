#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int a[10];
int b[10];

int main()
{
    int n;
    scanf("%d",&n);
    int temp;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&temp);
        a[temp]++;
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&temp);
        b[temp]++;
    }
    int ans=0;
    for(int i=1; i<=5; i++)
    {
        if(abs(a[i]-b[i])%2)
        {
            puts("-1");
            return 0;
        }
        ans+=abs(a[i]-b[i])/2;
    }
    printf("%d\n",ans/2);
    return 0;
}
