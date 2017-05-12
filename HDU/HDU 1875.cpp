//Kruskal�㷨��
/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAXN 105
int par[MAXN],x[MAXN],y[MAXN];

struct island
{
    int code1;
    int code2;
    double len;
} is[5005];

int cmp(struct island a,struct island b)
{
    return a.len < b.len;
}

int find_set(int r)
{
    if(r!=par[r])
        return par[r]=find_set(par[r]);
    return par[r];
}

double merge_set(int x,int y,double len)
{
    int setx,sety;
    setx=find_set(x);
    sety=find_set(y);
    if(setx==sety)
        return 0;
    par[setx]=sety;
    return len*100;
}

int main()
{
    int t,n,count,node;
    double sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
            par[i]=i;
        for(int i=1; i<=n; i++)
            scanf("%d %d",&x[i],&y[i]);
        count=0;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                is[count].code1=i;
                is[count].code2=j;
                is[count].len=sqrt( pow( (x[i]-x[j]) ,2) + pow( (y[i]-y[j]),2) );
                count++;
            }
        }
        sort(is,is+count,cmp);
        sum=0;
        for(int i=0; i<count; i++)
        {
            if(is[i].len>=10 && is[i].len<=1000)
            {
                sum+=merge_set(is[i].code1,is[i].code2,is[i].len);
            }
        }
        node=-1;
        for(int i=1; i<=n; i++)
        {
            if(par[i]==i)
                node++;
        }
        if(node>0)
            printf("oh!\n");
        else
            printf("%.1lf\n",sum);
    }
    return 0;
}
*/


//Prim�㷨��
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

int n;
double mp[MAXN][MAXN];
bool vis[MAXN];//����Ƿ��Ѿ�������С���������Ǹ���������
double dis[MAXN];//��¼�����Ѿ�������С������������������Ԫ�ص���� ���ϵ���С����
int x[MAXN],y[MAXN];

double dist(int i,int j)
{
    return sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

void prim()
{
    double sum=0;
    memset(vis,0,sizeof(vis));
    int pos=1;//��1��ʼ
    for(int i=1; i<=n; i++) //��һ�θ�dis��ֵ
        dis[i]=mp[1][i];
    vis[1]=1;   //�Ѿ��ҵ�һ����1������n-1��
    for(int i=1; i<n; i++)
    {
        double Min=INF;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && Min>dis[j])//����һ���㵽������ϵ���Сֵ
            {
                Min=dis[j];//���������Сֵ
                pos=j;//���������
            }
        }
        if(Min==INF)
        {
            printf("oh!\n");
            return ;
        }
        sum+=Min;
        vis[pos]=1;//�Ѹո��ҵ����������뼯��
        for(int j=1; j<=n; ++j) //����dis����
        {
            if(!vis[j] && dis[j]>mp[pos][j])
            {
                dis[j]=mp[pos][j];
            }
        }
    }
    printf("%.1lf\n",sum*100);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                mp[i][j]=dist(i,j);
                if(mp[i][j]>1000 || mp[i][j]<10)
                {
                    mp[i][j]=INF;
                }
            }
        }
        prim();
    }
    return 0;
}
