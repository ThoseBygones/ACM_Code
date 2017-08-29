//单调栈
/*补充知识——
单调栈解决的是以某个值为最小（最大）值的最大区间。
实现方法：
    求最小值（最大值）的最大区间，维护一个递增（递减）的栈。
    当遇到一个比栈顶小的值的时候开始弹栈，弹栈停止的位置到这个值的区间即为此值左边的最大区间；
    同时，当一个值被弹掉的时候也就意味着比它更小（更大）的值来了，也可以计算被弹掉的值得右边的最大区间。

单调队列解决的是区间最小（最大）值。
实现方法：
    求区间最小（最大）值，就维护一个递增的双端队列，队中保存原始序列的标号。
    当即将入队的元素的值比队尾的元素的值小（大）的时候就不断弹掉队尾，知道出现比它更小的值。
    当即将入队的元素队首元素的跨度（即将入队元素的序号到队首元素序列的区间）大于规定区间时就不断弹掉队首，直到跨度小于或等于所规定的区间。
    如此可保证队首元素为最小（最大）值，（但不能保证队尾就是原始序列中的最大（最小）值），并维护区间长度。
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define LL long long

int a[MAXN];
int l[MAXN];    //l[i]为从a[i]向左数第一个比a[i]小（大）的数字的下标
int r[MAXN];    //r[i]为从a[i]向右数第一个比a[i]小（大）的数字的下标

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    LL ans=0;
    stack <int> sl,sr;
    //处理区间最小值
    for(int i=0; i<n; i++)
    {
        while(sl.size() && a[i]>a[sl.top()])
            sl.pop();
        if(sl.size())
            l[i]=sl.top();
        else
            l[i]=-1;
        sl.push(i);
    }
    for(int i=n-1; i>=0; i--)
    {
        while(sr.size() && a[i]>=a[sr.top()])
            sr.pop();
        if(sr.size())
            r[i]=sr.top();
        else
            r[i]=n;
        sr.push(i);
    }
    for(int i=0; i<n; i++)
        ans+=(LL)a[i]*(LL)(r[i]-i)*(LL)(i-l[i]);

    while(!sl.empty())
        sl.pop();
    while(!sr.empty())
        sr.pop();

    //处理区间最大值
        for(int i=0; i<n; i++)
    {
        while(sl.size() && a[i]<a[sl.top()])
            sl.pop();
        if(sl.size())
            l[i]=sl.top();
        else
            l[i]=-1;
        sl.push(i);
    }
    for(int i=n-1; i>=0; i--)
    {
        while(sr.size() && a[i]<=a[sr.top()])
            sr.pop();
        if(sr.size())
            r[i]=sr.top();
        else
            r[i]=n;
        sr.push(i);
    }
    for(int i=0; i<n; i++)
        ans-=(LL)a[i]*(LL)(r[i]-i)*(LL)(i-l[i]);
    printf("%I64d\n",ans);
    return 0;
}
