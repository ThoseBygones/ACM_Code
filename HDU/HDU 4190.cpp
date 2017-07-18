#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 500005
#define INF 0x3f3f3f3f

int city[MAXN];
int n,b;

bool biSearch(int val)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        if(city[i]%val)
            sum+=(city[i]/val+1);
        else
            sum+=city[i]/val;
    }
    if(sum<=b)
        return true;
    return false;
}

int main()
{
    while(~scanf("%d%d",&n,&b))
    {
        if(n==-1 && b==-1)
            break;
        for(int i=0; i<n; i++)
            scanf("%d",&city[i]);
        int l=0,r=INF;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(biSearch(mid))
                r=mid-1;
            else
                l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
