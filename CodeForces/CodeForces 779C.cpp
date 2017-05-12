#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

struct Items
{
    int now;
    int later;
} p[200005];

int n,k;

bool cmp(Items a,Items b)
{
    return (a.now-a.later)<(b.now-b.later);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&p[i].now);
    for(int i=0; i<n; i++)
        scanf("%d",&p[i].later);
    sort(p,p+n,cmp);
    int ans=0;
    int cnt=0;
    int t=0;
    while(p[t].now<p[t].later || k>0)
    {
        //cout << "#" << p[t].now << endl;
        ans+=p[t].now;
        k--;
        t++;
    }
    //puts("ok");
    while(t<n)
    {
        //cout << "#" << p[t].later << endl;
        ans+=p[t].later;
        t++;
    }
    printf("%d\n",ans);
    return 0;
}
