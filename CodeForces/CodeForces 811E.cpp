//线段树+并查集
/*
用线段树维护每列的状况：一个sum表示这一块的联通块个数；ls[i],rs[i]表示这块中第i行左边和右边的标号；标号用来表示属于哪一个联通块。
因为行数比较小所以可以对于每个区间的左右两列维护并查集。
维护的东西必须保证在该区间中可以连通的两个位置的编号相同。
每次PushUp（向上更新），先是sum相加，一行行判断是否能合并成一个联通块。如果左右数值相同而且左右标号不同的话，sum--。
左右标号用并查集合并。两个区间合并的时候，将两个区间左右两列的编号在并查集中的父亲赋值成自己。
如果两个区间相邻的位置颜色相同就用并查集合并起来，然后此时再从并查集中查询区间左右列的编号即可。
也就是说我们每个区间的左右两列维护的是一个连通块的编号，合并的时候用并查集进行合并。
*/

#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define MAXN 100005
#define INF 0x3f3f3f3f

typedef int Type;

class SegTree
{
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1

public:
    struct Node
    {
        Type sum;
        Type L[15];
        Type R[15];
        Node() {}
        Node(Type sum,Type *L,Type *R)
        {
            sum = 0;
            memset(L,0,sizeof(L));
            memset(R,0,sizeof(R));
        }
    } t[MAXN<<2];

    int fa[MAXN<<4];
    int mat[15][MAXN];
    int n,m,q;
    int cnt;

    int findset(int x)
    {
        if(x!=fa[x])
            return fa[x]=findset(fa[x]);
        return fa[x];
    }

    void init(int n,int m,int q)
    {
        this -> n = n;
        this -> m = m;
        this -> q = q;
        cnt = 0;
    }

    Node PushUp(Type mid,Node lnode,Node rnode)
    {
        Node temp;
        temp.sum = lnode.sum + rnode.sum;
        for(int i=1; i<=n; i++) //初始化
        {
            fa[lnode.L[i]] = lnode.L[i];
            fa[rnode.L[i]] = rnode.L[i];
            fa[lnode.R[i]] = lnode.R[i];
            fa[rnode.R[i]] = rnode.R[i];
        }
        for(int i=1; i<=n; i++)
        {
            if(mat[i][mid] == mat[i][mid+1])
            {
                int rx = findset(rnode.L[i]);
                int ry = findset(lnode.R[i]);
                if(rx != ry)
                {
                    temp.sum--;
                    fa[ry] = rx;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            temp.L[i]=findset(lnode.L[i]);
            temp.R[i]=findset(rnode.R[i]);
        }
        return temp;
    }

    void build(Type l,Type r,int rt)
    {
        if(l == r)
        {
            for(int i=1; i<=n; i++)
            {
                if(mat[i][l]==mat[i-1][l])
                    t[rt].L[i]=t[rt].R[i]=t[rt].L[i-1];
                else
                {
                    t[rt].L[i]=t[rt].R[i]=++cnt;
                    t[rt].sum++;
                }
            }
            return ;
        }
        Type mid = (l + r) >> 1;
        build(lson);
        build(rson);
        t[rt] = PushUp(mid,t[rt<<1],t[rt<<1|1]);
    }

    Node query(Type L,Type R,Type l,Type r,int rt)
    {
        //cout << l << " " << r << endl;
        if(L<=l && r<=R)
        {
            return t[rt];
        }
        Type mid = (l + r) >> 1;
        if(R<=mid)
            return query(L,R,lson);
        else if(L>mid)
            return query(L,R,rson);
        else
        {
            //cout << "Go " << l << " " << r  << endl;
            return PushUp(mid,query(L,R,lson),query(L,R,rson));
        }
    }

    void solve()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                scanf("%d",&mat[i][j]);
        }
        build(1,m,1);
        /*for(int i=1; i<=10; i++)
        {
            cout << i << " # " << sum[i] << endl;
            for(int j=1; j<=8; j++)
                cout << L[i][j] << " " << R[i][j] << endl;
        }
        */
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Node ans=query(x,y,1,m,1);
            /*for(int i=1; i<=10; i++)
            {
                cout << i << " # " << sum[i] << endl;
                for(int j=1; j<=8; j++)
                    cout << L[i][j] << " " << R[i][j] << endl;
            }*/
            printf("%d\n",ans.sum);
        }
    }
} segtree;

int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    segtree.init(n,m,q);
    segtree.solve();
    return 0;
}
