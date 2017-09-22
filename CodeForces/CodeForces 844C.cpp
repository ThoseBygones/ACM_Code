#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

struct Node
{
    int val;
    int id;
    bool flag;  //是否在自己应该在的位置
} a[MAXN];

priority_queue <int,vector<int>,greater<int> > pq[MAXN];

bool cmp(Node x,Node y)
{
    return x.val<y.val;
}

void dfs(int pos,int k)
{
    int id=a[pos].id;
    pq[k].push(id);
    if(a[id].flag)
        return ;
    a[id].flag=true;
    dfs(id,k);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i].val);
        a[i].id=i;
        a[i].flag=false;
    }
    sort(a+1,a+1+n,cmp);
    int k=0;
    for(int i=1; i<=n; i++)
    {
        if(!a[i].flag)
        {
            a[i].flag=true;
            dfs(i,k);
            k++;
        }
    }
    printf("%d\n",k);
    for(int i=0; i<k; i++)
    {
        printf("%d",pq[i].size());
        while(!pq[i].empty())
        {
            printf(" %d",pq[i].top());
            pq[i].pop();
        }
        puts("");
    }
    return 0;
}
