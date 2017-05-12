#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 505
#define INF 10000000000.0
using namespace std;

struct Outposts
{
    double x;
    double y;
} op[MAXN];

double arc[MAXN][MAXN];    //�ڽӾ���
double dis[MAXN];  //��¼��С������
double Min[MAXN];  //��¼����֮�����Сֵ
int vis[MAXN];  //��¼ĳһ���Ƿ�������С��������
int n,s,p;

/*double dist(Outposts a,Outposts b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}*/

void prim()
{
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=p; i++)
        dis[i]=arc[1][i];
    vis[1]=1;
    int temp;
    for(int i=1; i<p; i++)
    {
        Min[i]=INF;
        temp=-1;
        for(int j=1; j<=p; j++)
        {
            if(!vis[j] && dis[j]<Min[i])
            {
                temp=j;
                Min[i]=dis[j];
            }
        }
        vis[temp]=1;
        for(int j=1; j<=p; j++)
        {
            if(!vis[j] && arc[temp][j]<dis[j])
                dis[j]=arc[temp][j];
        }
    }
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&s,&p);
        for(int i=1; i<=p; i++)
        {
            for(int j=1; j<=p; j++)
            {
                if(i==j)
                    arc[i][j]=0;
                else
                    arc[i][j]=arc[j][i]=INF;
            }
        }
        for(int i=1; i<=p; i++)
            scanf("%lf%lf",&op[i].x,&op[i].y);
        for(int i=1; i<p; i++)
        {
            for(int j=i+1; j<=p; j++)
            {
                double len=sqrt((op[i].x-op[j].x)*(op[i].x-op[j].x)+(op[i].y-op[j].y)*(op[i].y-op[j].y));
                arc[i][j]=arc[j][i]=min(arc[i][j],len);
            }
        }
        prim();
        sort(Min+1,Min+p);
        printf("%.2lf\n",Min[p-s]);
    }
    return 0;
}

//G++�ύ�����Ϊ%d�������Ϊ%.2f���ṹ����double�ĳ�int����AC��
