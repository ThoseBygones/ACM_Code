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
    int w;

    void PushUP(int rt)
    {
        Max[rt] = max(Max[rt<<1],Max[rt<<1|1]);
    }

    void build(int w,int l,int r,int rt)
    {
        Max[rt] = w;
        if(l == r)
            return ;
        int m = (l + r) >> 1;
        build(w,lson);
        build(w,rson);
    }

    int updateNode(int val,int l,int r,int rt)
    {
        if(l == r)
        {
            Max[rt] -= val;
            return l;
        }
        int m = (l + r) >> 1;
        int ret = -1;
        if(Max[rt<<1] >= val)
            ret = updateNode(val,lson);
        else if(Max[rt<<1|1] >= val)
            ret = updateNode(val,rson);
        PushUP(rt);
        return ret;
    }
} segtree;

int main()
{
    int h,w,n;
    while(~scanf("%d%d%d",&h,&w,&n))
    {
        h=min(h,n);
        segtree.build(w,1,h,1);
        while(n--)
        {
            int x;
            scanf("%d",&x);
            if(w<x)
                puts("-1");
            else
                printf("%d\n",segtree.updateNode(x,1,h,1));
        }
    }
    return 0;
}
