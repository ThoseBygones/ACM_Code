#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define LL long long

priority_queue <LL,vector<LL>,greater<LL> > pq;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        LL temp;
        scanf("%I64d",&temp);
        pq.push(temp);
    }
    LL sum=0;
    if(!(n&1))
        pq.push(0);
    while(pq.size()>=2)
    {
        LL tot=0;
        tot+=pq.top();
        pq.pop();
        tot+=pq.top();
        pq.pop();
        tot+=pq.top();
        pq.pop();
        pq.push(tot);
        sum+=tot;
    }
    printf("%I64d\n",sum);
    return 0;
}
