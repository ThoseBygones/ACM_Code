#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005

class SegTree
{
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

public:
    int a[MAXN];
    int Sum[MAXN<<2];

    void PushUP(int rt)
    {
        Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
    }

    void build(int l,int r,int rt)
    {
        Sum[rt] = 0;
        if(l == r)
            return ;
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
    }

    void updateNode(int p,int val,int l,int r,int rt)
    {
        if(l == r)
        {
            Sum[rt]++;
            return ;
        }
        int m = (l + r) >> 1;
        if(p <= m)
            updateNode(p,val,lson);
        else
            updateNode(p,val,rson);
        PushUP(rt);
    }

    int querySum(int L,int R,int l,int r,int rt)
    {
        if(L <= l && r <= R)
            return Sum[rt];
        int m = (l + r) >> 1;
        int ret = 0;
        if(L <= m)
            ret += querySum(L,R,lson);
        if(R > m)
            ret += querySum(L,R,rson);
        return ret;
    }

    int findMinInv(int n)
    {
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum += querySum(a[i],n-1,0,n-1,1);  //求出每个点的你叙述
            updateNode(a[i],n-1,0,n-1,1);
        }
        int ans = sum;
        for(int i=0; i<n; i++)
        {
            sum += n - a[i] - 1 - a[i];
            //假设小于a的个数为t,那么大于a的个数就是n-t-1.
            //当把a移动左移一位时，原来比a大的现在都成了a的逆序对，即逆序数增加n-t-1；但是原来比a小的构成逆序对的数都变成了顺序，因此逆序对减少t
            //所以新序列的逆序数为n-t-t-1
            ans = min(sum,ans);
        }
        printf("%d\n",ans);
    }
} segtree;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        segtree.build(0,n-1,1);
        segtree.findMinInv(n);
    }
    return 0;
}
