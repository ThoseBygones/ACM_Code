#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int t[MAXN];
int n,T;

priority_queue <int> pq;

int main()
{
    scanf("%d%d",&n,&T);
    for(int i=1; i<=n; i++)
        scanf("%d",&t[i]);
    int ans=0;
    for(int i=1; i<=min(n,T-1); i++)    //枚举每个时间点能吃的数量（最后一分钟才到达的不能吃）
    {
        if(t[i]<T)
            pq.push(t[i]-i);
        while(!pq.empty() && pq.top()>=T-i)
            pq.pop();
        ans=max(ans,(int)pq.size());
    }
    printf("%d\n",ans);
    return 0;
}
