#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 10005

struct Fuel
{
    int pos;
    int val;
    bool operator <(const Fuel &a)const
    {
        return a.val>val;
    }
} a[MAXN];

priority_queue <Fuel> pq;

bool cmp(Fuel a, Fuel b)
{
    return a.pos>b.pos;
}

int main()
{
    int n,l,p;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&a[i].pos,&a[i].val);
    scanf("%d%d",&l,&p);
    for(int i=1; i<=n; i++)
        a[i].pos=l-a[i].pos;
    a[0].pos=l;
    a[0].val=0;
    sort(a,a+n+1,cmp);
    int ans=0;  //加油次数
    int curpos=0;  //现在的位置
    int tank=p; //油箱中汽油量
    for(int i=n; i>=0; i--)
    {
        int d=a[i].pos-curpos;
        while(tank<d)   //油量不够到达下一个加油站，则加油
        {
            if(pq.empty())
            {
                puts("-1");
                return 0;
            }
            tank+=pq.top().val;
            //cout << pq.top().val << endl;
            pq.pop();
            ans++;
        }
        tank-=d;
        curpos=a[i].pos;
        pq.push(a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
