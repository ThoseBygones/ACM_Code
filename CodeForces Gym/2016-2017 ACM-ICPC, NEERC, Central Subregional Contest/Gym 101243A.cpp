#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    int ans;
    scanf("%d%d",&n,&k);
    if(n<=k)
        ans=2;
    else
    {
        if(n*2%k==0)
            ans=n*2/k;
        else
            ans=n*2/k+1;
    }
    printf("%d\n",ans);
    return 0;
}
