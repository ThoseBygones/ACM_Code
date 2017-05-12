#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define MAXN 4005
#define INF 0x3f3f3f3f

int edge[MAXN][MAXN];   //�ڽӾ���
int degree[MAXN];   //����Ķ�
int u[MAXN],v[MAXN];    //�߶ε������˵�
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
                ans=min(ans,degree[u[i]]+degree[v[i]]+degree[j]);   //ö��һ����Ԫ����ܶ�������¼��С��
        }
    }
    if(ans!=INF)
        printf("%d\n",ans-6);   //��ȥÿ�������Ⱥͳ��ȹ�6����
    else
        puts("-1");
    return 0;
}
