#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define LL long long

int fa[MAXN];

int findset(int x)
{
    if(x!=fa[x])
        return findset(fa[x]);  //不能路径压缩，因为M操作相当于将某个结点分离出来
    return fa[x];
}

int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        if(n==0 && q==0)
            break;
        fa[1]=1;
        for(int i=2; i<=n; i++)
            scanf("%d",&fa[i]);
        LL ans=0;
        for(int i=1; i<=q; i++)
        {
            char op[2];
            int node;
            scanf("%s%d",op,&node);
            if(op[0]=='M')
                fa[node]=node;
            if(op[0]=='Q')
                ans+=findset(node);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
