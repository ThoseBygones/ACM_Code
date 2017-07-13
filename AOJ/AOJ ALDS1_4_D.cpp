#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define LL long long
#define INF 1000000000  //100000*10000

LL w[MAXN];
int n,k;

int check(LL val)
{
    int cnt=0;
    for(int i=0; i<k; i++)
    {
        LL sum=0;
        while(sum+w[cnt]<=val)
        {
            sum+=w[cnt];
            cnt++;
            if(cnt==n)
                return n;
        }
    }
    return cnt;
}

int biSearch()
{
    LL left=0,right=INF;
    LL ans;
    while(left<=right)
    {
        LL mid=(left+right)>>1;
        if(check(mid)>=n)
        {
            ans=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&w[i]);
    LL ans=biSearch();
    printf("%d\n",ans);
}
