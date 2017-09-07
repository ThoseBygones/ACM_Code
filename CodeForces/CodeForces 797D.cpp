#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f

struct Node
{
    int l,r;
    int val;
} tree[MAXN];

map <int,int> vis;

bool fa[MAXN];  //记录子结点是否存在
int n;

void dfs(int u,int lval,int rval)
{
    if(u==-1)
        return ;
    if(lval<=tree[u].val && tree[u].val<=rval)
    {
        if(vis[tree[u].val])
            vis[tree[u].val]=0;
    }
    dfs(tree[u].l,lval,min(tree[u].val,rval));
    dfs(tree[u].r,max(tree[u].val,lval),rval);
}

int main()
{
    scanf("%d",&n);
    memset(fa,false,sizeof(fa));
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d",&tree[i].val,&tree[i].l,&tree[i].r);
        if(tree[i].l!=-1)
            fa[tree[i].l]=true;
        if(tree[i].r!=-1)
            fa[tree[i].r]=true;
        vis[tree[i].val]++;
    }
    int root;
    for(int i=1; i<=n; i++)
    {
        if(!fa[i])
        {
            root=i;
            break;
        }
    }
    dfs(root,-INF,INF);
    for(int i=1; i<=n; i++)
    {
        cnt+=vis[tree[i].val];
        vis[tree[i].val]=0;
    }
    printf("%d\n",cnt);
}
