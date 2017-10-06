#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1005

int g[MAXN][MAXN];  //�ڽӾ���
int fa[MAXN];   //��¼����
int in[MAXN];   //���
int out[MAXN];  //����
int belong[MAXN];   //��¼ÿ�������ڵļ��ϱ�ţ�1--���᣻2--�еȣ�3--����
int n,m;

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

void mergeset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
        fa[xx]=yy;
}

void init()
{
    memset(g,0,sizeof(g));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(belong,0,sizeof(belong));
    for(int i=1; i<=n; i++)
        fa[i]=i;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    init();
    for(int i=1; i<=m; i++)
    {
        int u,v;
        char c;
        scanf("%d%c%d",&u,&c,&v);
        if(c=='=')
            mergeset(u,v);
        if(c=='<')  //��������ͼ������С���ָ��������ĵ�
        {
            g[u][v]=1;  //��¼˫���ϵ
            g[v][u]=-1;
            out[u]++;
            in[v]++;
        }
        if(c=='>')
        {
            g[v][u]=1;
            g[u][v]=-1;
            in[u]++;
            out[v]++;
        }
    }
    for(int i=1; i<=n; i++) //���Խ������ͳ�Ƶ����ڵ�
    {
        in[findset(i)]+=in[i];
        out[findset(i)]+=out[i];
    }
    for(int i=1; i<=n; i++) //�����и��ڵ����ͳ��
    {
        if(findset(i)==i && in[i] && out[i])
            belong[i]=2;
    }

    for(int i=1; i<=n; i++)
    {
        if(belong[findset(i)]==2)
        {
            for(int j=1; j<=n; j++)
            {
                if(g[i][j]==1)
                    belong[findset(j)]=3;
                if(g[i][j]==-1)
                    belong[findset(j)]=1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        int temp=belong[findset(i)];
        if(temp==0)
            printf("?");
        if(temp==1)
            printf("B");
        if(temp==2)
            printf("R");
        if(temp==3)
            printf("W");
    }
    puts("");
    return 0;
}
