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
    int Col[MAXN<<2];   //每段的颜色，用二进制表示，每一位表示一种颜色
    int add[MAXN<<2];

    void PushUp(int rt)
    {
        Col[rt] = Col[rt<<1] | Col[rt<<1|1];
    }

    void PushDown(int rt)
    {
        if(add[rt])
        {
            Col[rt<<1] = Col[rt<<1|1] = add[rt];
            add[rt<<1] = add[rt<<1|1] = add[rt];
            add[rt] = 0;
        }
    }

    void build(int l,int r,int rt)
    {
        add[rt] = 0;
        if(l == r)
        {
            Col[rt] = 1;
            return ;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        PushUp(rt);
    }

    void updateInterval(int L,int R,int val,int l,int r,int rt)
    {
        if(L <= l && r <= R)
        {
            add[rt] = 1 << (val - 1);
            Col[rt] = 1 << (val - 1);
            return ;
        }
        PushDown(rt);
        int m = (l + r) >> 1;
        if(L <= m)
            updateInterval(L,R,val,lson);
        if(R > m)
            updateInterval(L,R,val,rson);
        PushUp(rt);
    }

    int query(int L,int R,int l,int r,int rt)
    {
        if(L <= l && r <= R)
            return Col[rt];
        PushDown(rt);
        int ret = 0;
        int m = (l + r) >> 1;
        if(L <= m)
            ret |= query(L,R,lson);
        if(R > m)
            ret |= query(L,R,rson);
        return ret;
    }
} segtree;

int main()
{
    int L,T,O;
    scanf("%d%d%d",&L,&T,&O);
    segtree.build(1,L,1);
    while(O--)
    {
        char op[2];
        scanf("%s",op);
        if(op[0]=='C')
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a>b)
                swap(a,b);
            segtree.updateInterval(a,b,c,1,L,1);
        }
        if(op[0]=='P')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b)
                swap(a,b);
            int ans=segtree.query(a,b,1,L,1);
            int cnt=0;
            while(ans)
            {
                if(ans&1)   //某颜色存在
                    cnt++;
                ans>>=1;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
