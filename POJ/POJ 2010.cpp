#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 100010
#define INF 0x3f3f3f3f

pair <int,int> cow[MAXN];
int low[MAXN],high[MAXN];   //比第i只牛分数低和高的牛需要的总助学金

int main()
{
    int n,c,f;
    scanf("%d%d%d",&n,&c,&f);
    for(int i=0; i<c; i++)
        scanf("%d%d",&cow[i].first,&cow[i].second);
    sort(cow,cow+c);
    priority_queue <int> pq;
    int sum=0;
    for(int i=0; i<c; i++)
    {
        if(pq.size()==n/2)
            low[i]=sum;
        else
            low[i]=INF;
        pq.push(cow[i].second);
        sum+=cow[i].second;
        if(pq.size()>n/2)
        {
            sum-=pq.top();
            pq.pop();
        }
    }
    while(!pq.empty())
        pq.pop();
    sum=0;
    for(int i=c-1; i>=0; i--)
    {
        if(pq.size()==n/2)
            high[i]=sum;
        else
            high[i]=INF;
        pq.push(cow[i].second);
        sum+=cow[i].second;
        if(pq.size()>n/2)
        {
            sum-=pq.top();
            pq.pop();
        }
    }
    int ans=-1;
    for(int i=c-1; i>=0; i--)
    {
        if(low[i]+cow[i].second+high[i]<=f)
        {
            ans=cow[i].first;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
