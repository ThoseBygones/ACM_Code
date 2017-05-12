#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 30

int edge[MAXN][MAXN];   //邻接矩阵
int indegree[MAXN],outdegree[MAXN]; //入度和出度
int vis[MAXN];
int start;

void dfs(int x)
{
    for(int i=0; i<26; i++)
    {
        if(edge[x][i])
        {
            edge[x][i]=0;
            dfs(i);
        }
    }
}

bool isEuler()
{
    int mark1,mark2,mark3;
    int temp;
    mark1=mark2=mark3=0;    //mark1为出度与入度只差为1的点的数量，mark2为出度与入度之差为-1的点的数量，mark3为入度与出度之差的绝对值大于1的点数量的
    for(int i=0; i<26; i++)
    {
        if(outdegree[i]-indegree[i]==-1)
            mark1++;
        if(outdegree[i]-indegree[i]==1) //若为欧拉通路，则标记起点
        {
            start=i;
            mark2++;
        }
        if(indegree[i]==outdegree[i] && indegree[i]!=0) //判断所有点是否都入度等于出度，且不为零
            temp=i; //记录可能的起点
        if(abs(indegree[i]-outdegree[i])>1)
            mark3++;
    }
    if(mark1>1 || mark2>1 || mark3>0)
        return false;
    if(mark2==0)
        start=temp;
    return true;
}

int main()
{
    char str[1005];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(edge,0,sizeof(edge));
        memset(indegree,0,sizeof(indegree));
        memset(outdegree,0,sizeof(indegree));
        memset(vis,0,sizeof(vis));
        while(n--)
        {
            scanf("%s",str);
            int len=strlen(str);
            int u=str[0]-'a';
            int v=str[len-1]-'a';
            edge[u][v]=1;
            indegree[v]++;
            outdegree[u]++;
        }
        bool flag=false;
        if(isEuler())
        {
            flag=true;
            dfs(start);
            for(int i=0; i<26; i++)
            {
                for(int j=0; j<26; j++)
                {
                    if(edge[i][j])
                    {
                        flag=false;
                        break;
                    }
                }
            }
        }
        if(flag)
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}
