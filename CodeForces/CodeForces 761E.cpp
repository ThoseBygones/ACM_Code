#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 35
#define MAXM 1<<30

struct Points
{
    int x;
    int y;
} ans[MAXN];

vector <int> edge[MAXN]; //STL�ڽӱ�

int degree[MAXN];   //ÿ�����Ķ�
int dx[]={0,-1,0,1}; //��������
int dy[]={-1,0,1,0}; //��������
int n;

void dfs(int u,int from,int x,int y,int len,int dir)    //dirΪ���ķ���
{
    int ndir=0; //�µķ���
    ans[u].x=x;
    ans[u].y=y;
    for(int i=0; i<edge[u].size(); i++)
    {
        int v=edge[u][i];
        if(v==from) //�����ظ��ڵ�
            continue;
        if((ndir+2)%4==dir) //��һ���ߵķ���������ʱ�ķ����෴
            ndir++;
        int nx=x+dx[ndir]*len;
        int ny=y+dy[ndir]*len;
        dfs(v,u,nx,ny,len/2,ndir);  //��һ���Ĳ�����2����������2^30,2^29,...,2^1,2^0��2^k������Ϊ2^0+2^1+...+2^(k-1)<2^k
        ndir++;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    //puts("ok");
    bool flag=true;
    for(int i=1; i<=n; i++)
    {
        if(degree[i]>4) //��������4�϶���������
            flag=false;
    }
    if(!flag)
        puts("NO");
    else
    {
        dfs(1,-1,0,0,1<<30,-1);
        puts("YES");
        for(int i=1; i<=n; i++)
            printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}
