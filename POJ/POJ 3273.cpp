#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f

int money[MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    int Max=0;
    int left,right,cnt;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",money+i);
        sum+=money[i];
        Max=max(money[i],Max);
    }
    left=Max;
    right=sum;
    int ans;
    while(left<=right)
    {
        int mid=(left+right)/2;
        sum=0;
        cnt=1;
        for(int i=1; i<=n; i++)
        {
            sum+=money[i];
            if(sum>mid)
            {
                sum=money[i];
                cnt++;
            }
        }
        if(cnt<=m)
        {
            ans=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
