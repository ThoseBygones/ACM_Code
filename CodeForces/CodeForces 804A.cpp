#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    if(n%2)
        ans=n/2;
    else
        ans=n/2-1;
    printf("%d\n",ans);
    return 0;
}
