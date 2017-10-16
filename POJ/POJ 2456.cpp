#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100010

int x[MAXN];
int n,c;

bool check(int val)
{
    int cnt=1;
    int pre=x[0];   //上一个barn的位置
    for(int i=1; i<n; i++)
    {
        if(x[i]-pre>=val)
        {
            cnt++;
            pre=x[i];
            if(cnt>=c)
                return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&c);
    for(int i=0; i<n; i++)
        scanf("%d",&x[i]);
    sort(x,x+n);
    int ans=-1;
    int l=0,r=x[n-1]-x[0];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
