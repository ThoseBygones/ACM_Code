#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 1e9
int a[100005];

int main()
{
    int n;
    int Max=0,Min=INF;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",a+i);
        Max=max(Max,a[i]);
        Min=min(Min,a[i]);
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]<Max && a[i]>Min)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
