#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF 0x7fffffff

struct Line
{
    int l;
    int r;
    int c;
    bool operator <(const Line &a)const
    {
        return r>a.r;
    }
} line[MAXN];

int dp[MAXN];   //长度为i的时候的最小花费

bool cmp(Line a,Line b)
{
    return a.l<b.l;
}

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=0; i<MAXN; i++)
        dp[i]=INF;
    for(int i=0; i<n; i++)
        scanf("%d%d%d",&line[i].l,&line[i].r,&line[i].c);
    sort(line,line+n,cmp);
    priority_queue <Line> pq;
    int ans=INF;
    for(int i=0; i<n; i++)
    {
        int len1=line[i].r-line[i].l+1;
        if(len1>x)
            continue;
        while(!pq.empty() && line[i].l>pq.top().r)
        {
            int len2=pq.top().r-pq.top().l+1;
            dp[len2]=min(dp[len2],pq.top().c);
            pq.pop();
        }
        pq.push(line[i]);
        if(dp[x-len1]==INF)
            continue;
        ans=min(ans,line[i].c+dp[x-len1]);
    }
    if(ans!=INF)
        printf("%d\n",ans);
    else
        puts("-1");
    return 0;
}
