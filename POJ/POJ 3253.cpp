#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define LL long long
using namespace std;

priority_queue <int, vector<int>, greater<int> > pq;

int main()
{
    int n;
    scanf("%d",&n);
    LL ans=0;
    for(int i=1; i<=n; i++)
    {
        int temp;
        scanf("%d",&temp);
        pq.push(temp);
    }
    while(pq.size()>1)
    {
        int sum=0;
        sum+=pq.top();
        pq.pop();
        sum+=pq.top();
        pq.pop();
        pq.push(sum);
        ans+=sum;
    }
    printf("%lld\n",ans);
    return 0;
}
