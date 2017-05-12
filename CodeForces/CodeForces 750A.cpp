#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int left=240-k;
    int i;
    for(i=1; i<=n; i++)
    {
        if(i*5<=left)
            left-=i*5;
        else
            break;
    }
    printf("%d\n",i-1);
    return 0;
}
