#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 50005

struct Cow
{
    int l;
    int r;
    int id;
    bool operator <(const Cow &a) const
    {
        if(r==a.r)
            return l>a.r;
        return r>a.r;
    }
} cow[MAXN];

int sid[MAXN];

bool cmp(Cow a,Cow b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&cow[i].l,&cow[i].r);
        cow[i].id=i;
    }
    sort(cow,cow+n,cmp);
    priority_queue <Cow> pq;
    pq.push(cow[0]);
    sid[cow[0].id]=1;
    int ans=1;  //初始化总stall数
    for(int i=1; i<n; i++)
    {
        if(!pq.empty() && pq.top().r<cow[i].l)
        {
            sid[cow[i].id]=sid[pq.top().id];
            pq.pop();
        }
        else
        {
            ans++;  //新开一个stall
            sid[cow[i].id]=ans;
        }
        pq.push(cow[i]);
    }
    printf("%d\n",ans);
    for(int i=0; i<n; i++)
        printf("%d\n",sid[i]);
    return 0;
}
