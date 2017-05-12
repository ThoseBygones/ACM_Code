#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

struct Edge
{
    int u;
    int v;
} edge[MAXN];

int color[MAXN];    //每个结点的颜色
int cnt[MAXN];  //每个结点与其相邻结点颜色不同的次数
int sum;    //全图中每个结点与其相邻结点颜色不同的次数

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
        scanf("%d%d",&edge[i].u,&edge[i].v);
    for(int i=1; i<=n; i++)
        scanf("%d",&color[i]);
    for(int i=1; i<n; i++)
    {
        if(color[edge[i].u]!=color[edge[i].v])  //相邻结点颜色不同
        {
            sum++;  //总数+1
            cnt[edge[i].u]++;
            cnt[edge[i].v]++;   //两结点分别计数
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(cnt[i]==sum) //若存在这么个结点与其相邻结点颜色不同的次数 = 全图中每个结点与其相邻结点颜色不同的次数
        {
            puts("YES");
            printf("%d\n",i);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
