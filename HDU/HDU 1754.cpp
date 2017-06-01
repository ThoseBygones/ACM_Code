#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 200005

class SegTree
{
    #define lson l, m, rt << 1
    #define rson m+1, r, rt << 1 | 1

public:
    int Max[MAXN<<2];

    void PushUP(int rt)
    {
        Max[rt] = max(Max[rt<<1],Max[rt<<1|1]);
    }

    void build(int l,int r,int rt)
    {
        if(l == r)
        {
            scanf("%d",&Max[rt]);
            return ;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        PushUP(rt);
    }

    void updateNode(int p,int val,int l,int r,int rt)
    {
        if(l == r)
        {
            Max[rt] = val;
            return ;
        }
        int m = (l + r) >> 1;
        if(p <= m)
            updateNode(p,val,lson);
        else
            updateNode(p,val,rson);
        PushUP(rt);
    }

    int queryMax(int L,int R,int l,int r,int rt)
    {
        if(L <= l && r <= R)
            return Max[rt];
        int m = (l + r) >> 1;
        int ret = 0;
        if(L <= m)
            ret = max(ret,queryMax(L,R,lson));
        if(R > m)
            ret = max(ret,queryMax(L,R,rson));
        return ret;
    }
} segtree;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        segtree.build(1,n,1);
        while(m--)
        {
            char op[2];
            int a,b;
            scanf("%s%d%d",op,&a,&b);
            if(op[0]=='Q')
                printf("%d\n",segtree.queryMax(a,b,1,n,1));
            else if(op[0]=='U')
                segtree.updateNode(a,b,1,n,1);
        }
    }
    return 0;
}
