#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

class SegTree
{
    #define lson l, m, rt << 1
    #define rson m + 1, r, rt << 1 | 1

public:
    int n;
    int Sum[MAXN<<2];
    int Lazy[MAXN<<2];

    void PushUP(int rt)
    {
        Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
    }

    void PushDown(int rt,int val)
    {
        if(Lazy[rt])
        {
            Lazy[rt<<1] = Lazy[rt<<1|1] = Lazy[rt];
            Sum[rt<<1] = Lazy[rt] * (val - (val >> 1));
            Sum[rt<<1|1] = Lazy[rt] * (val >> 1);
            Lazy[rt] = 0;
        }
    }

    void build(int l,int r,int rt)
    {
        Lazy[rt] = 0;
        Sum[rt] = 1;
        if(l == r)
            return ;
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        PushUP(rt);
    }

    void updateInterval(int L,int R,int val,int l,int r,int rt)
    {
        if(L <= l && r <= R)
        {
            Lazy[rt] = val;
            Sum[rt] = val * (r - l + 1);
            return ;
        }
        PushDown(rt,r-l+1);
        int m = (l + r) >> 1;
        if(L <= m)
            updateInterval(L,R,val,lson);
        if(R > m)
            updateInterval(L,R,val,rson);
        PushUP(rt);
    }

    void init(int a)
    {
        n = a;
    }
} segtree;

int main()
{
    int t;
    int kase=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        segtree.init(n);
        segtree.build(1,n,1);
        while(q--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            segtree.updateInterval(a,b,c,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",kase++,segtree.Sum[1]);
    }
    return 0;
}
