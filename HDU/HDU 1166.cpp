#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 50005

class SegTree
{
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

public:
    int Sum[MAXN<<2];

    void PushUP(int rt)
    {
        Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
    }

    void build(int l,int r,int rt)
    {
        if(l == r)
        {
            scanf("%d",&Sum[rt]);
            return ;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        PushUP(rt);
    }

    void addNode(int p,int val,int l,int r,int rt)
    {
        if(l == r)
        {
            Sum[rt] = Sum[rt] + val;
            return ;
        }
        int m = (l + r) >> 1;
        if(p <= m)
            addNode(p,val,lson);
        else
            addNode(p,val,rson);
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
} segtree;

int main()
{
    int t;
    int kase=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        segtree.build(1,n,1);
        printf("Case %d:\n",kase++);
        char op[10];
        while(~scanf("%s",op))
        {
            if(op[0]=='E')
                break;
            int a,b;
            scanf("%d%d",&a,&b);
            if(op[0]=='Q')
                printf("%d\n",segtree.querySum(a,b,1,n,1));
            else if(op[0]=='A')
                segtree.addNode(a,b,1,n,1);
            else if(op[0]=='S')
                segtree.addNode(a,-b,1,n,1);
        }
    }
    return 0;
}
