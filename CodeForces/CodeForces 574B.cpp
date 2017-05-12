#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define MAXN 4005
#define INF 0x3f3f3f3f

int edge[MAXN][MAXN];   //邻接矩阵
int degree[MAXN];   //顶点的度
int u[MAXN],v[MAXN];    //线段的两个端点
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",u+i,v+i);
        degree[u[i]]++;
        degree[v[i]]++;
        edge[u[i]][v[i]]=edge[v[i]][u[i]]=1;
    }
    int ans=INF;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(edge[u[i]][j] && edge[j][v[i]])
                ans=min(ans,degree[u[i]]+degree[v[i]]+degree[j]);   //枚举一个三元组的总度数，记录最小的
        }
    }
    if(ans!=INF)
        printf("%d\n",ans-6);   //减去每个点的入度和出度共6个度
    else
        puts("-1");
    return 0;
}
