#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long
#define MAXN 100010

typedef LL Type;

class SegTree
{
    #define lson l, m, rt << 1
    #define rson m+1, r, rt << 1 | 1

public:
    Type Sum[MAXN<<2];
    Type Lazy[MAXN<<2];

    void PushUP(int rt)
    {
        Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
    }

    void PushDown(int rt,Type val)
    {
        if(Lazy[rt])
        {
            Lazy[rt<<1] += Lazy[rt];
            Lazy[rt<<1|1] += Lazy[rt];
            Sum[rt<<1] += Lazy[rt] * (val - (val >> 1));
            Sum[rt<<1|1] += Lazy[rt] * (val >> 1);
            Lazy[rt] = 0;
        }
    }

    void build(int l,int r,int rt)
    {
        Lazy[rt] = 0;
        if(l == r)
        {
            scanf("%lld",&Sum[rt]);
            return ;
        }
        Type m = (l + r) >> 1;
        build(lson);
        build(rson);
        PushUP(rt);
    }

    void updateInterval(Type L,Type R,Type val,Type l,Type r,int rt)
    {
        if(L <= l && r <= R)
        {
            Lazy[rt] += val;
            Sum[rt] += val * (r - l + 1);
            return ;
        }
        PushDown(rt,r-l+1);
        Type m = (l + r) >> 1;
        if(L <= m)
            updateInterval(L,R,val,lson);
        if(R > m)
            updateInterval(L,R,val,rson);
        PushUP(rt);
    }

    Type querySum(Type L,Type R,Type l,Type r,int rt)
    {
        if(L <= l && r <= R)
            return Sum[rt];
        PushDown(rt,r-l+1);
        Type m = (l + r) >> 1;
        Type ret = 0;
        if(L <= m)
            ret += querySum(L,R,lson);
        if(R > m)
            ret += querySum(L,R,rson);
        return ret;
    }
} segtree;

int main()
{
    Type n,q;
    scanf("%lld%lld",&n,&q);
    segtree.build(1,n,1);
    while(q--)
    {
        char op[2];
        scanf("%s",op);
        if(op[0]=='Q')
        {
            LL a,b;
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",segtree.querySum(a,b,1,n,1));
        }
        if(op[0]=='C')
        {
            LL a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            segtree.updateInterval(a,b,c,1,n,1);
        }
    }
    return 0;
}
