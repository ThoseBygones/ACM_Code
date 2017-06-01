#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 200005

class SegTree
{
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

public:
    int Sum[MAXN<<2];   //给定范围中空位的个数
    int ans[MAXN<<2];   //保存插入的值
    int pos[MAXN];
    int val[MAXN];

    void PushUP(int rt)
    {
        Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
    }

    void build(int l,int r,int rt)
    {
        Sum[rt] = r - l + 1;
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
            ans[rt] = val;
            Sum[rt]--;
            return ;
        }
        int m = (l + r) >> 1;
        if(p <= Sum[rt<<1]) //因为序号实际上是从大到小的，所以根据序号数与剩余空位数的比较关系可以确定插入的位置
            updateNode(p,val,lson);
        else
            updateNode(p-Sum[rt<<1],val,rson);  //p-Sum[rt<<1]寻找范围内最靠前的编号位
        PushUP(rt);
    }

    void print(int l,int r,int rt)
    {
        if(l == r)
        {
            printf("%d ",ans[rt]);
            return ;
        }
        int m = (l + r) >> 1;
        print(lson);
        print(rson);
    }

    void init(int n)
    {
        for(int i=1; i<=n; i++)
            scanf("%d%d",&pos[i],&val[i]);
        build(1,n,1);
        for(int i=n; i>=1; i--)
            updateNode(pos[i]+1,val[i],1,n,1);
    }
} segtree;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        segtree.init(n);
        segtree.print(1,n,1);
        puts("");
    }
    return 0;
}
