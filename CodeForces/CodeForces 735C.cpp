#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

LL a[90];

int main()
{
    a[1]=2;
    a[2]=3;
    for(int i=3; ; i++)
    {
        a[i]=a[i-1]+a[i-2];
        if(a[i]>1e18)
            break;
    }
    LL n;
    cin >> n;
    int left=1,right=87;
    int ans;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(n>=a[mid])
        {
            ans=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
