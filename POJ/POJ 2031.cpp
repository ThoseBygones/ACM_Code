//PrimÀ„∑®
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

#define eps 0.00000001
#define INF 100000.0
double ss[105][105];
int vis[105],n;

struct spaces
{
    double x;
    double y;
    double z;
    double r;
} p[10005];

bool intersect(double v)
{
    if(fabs(v)<eps || v<0)
        return true;
    return false;
}

double dis(spaces a,spaces b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))-a.r-b.r;
}

double prim()
{
    int temp;
    double sum=0.0;
    vis[1]=1;
    for(int i=1; i<n; i++)
    {
        double mmin=INF;
        for(int j=2; j<=n; j++)
        {
            if(vis[j]==0 && ss[1][j]<mmin)
            {
                mmin=ss[1][j];
                temp=j;
            }
        }
        sum+=ss[1][temp];
        vis[temp]=1;
        for(int j=2; j<=n; j++)
        {
            if(vis[j]==0 && ss[temp][j]<ss[1][j])
                ss[1][j]=ss[temp][j];
        }
    }
    return sum;
}

int main()
{
    while(cin >> n,n)
    {
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i!=j)
                    ss[i][j]=INF;
            }
        }

        for(int i=1; i<=n; i++)
            cin >> p[i].x >> p[i].y >> p[i].z >> p[i].r;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                double temp=dis(p[i],p[j]);
                if(intersect(temp))
                    ss[i][j]=ss[j][i]=0;
                else
                    ss[i][j]=ss[j][i]=temp;
            }
        }
        double ans=prim();
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}

//KruskalÀ„∑®
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 105
using namespace std;

int par[MAXN];
double ans;

struct Cell
{
    double x;
    double y;
    double z;
    double r;
} cell[MAXN];

struct Corridor
{
    int u;
    int v;
    double dis;
} cor[MAXN*MAXN];

double dist(Cell a,Cell b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

bool cmp(Corridor a,Corridor b)
{
    return a.dis<b.dis;
}

int findset(int r)
{
    if(r!=par[r])
        par[r]=findset(par[r]);
    return par[r];
}

void unionset(int i)
{
    int xx=findset(cor[i].u);
    int yy=findset(cor[i].v);
    if(xx!=yy)
    {
        par[xx]=yy;
        ans+=cor[i].dis;
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n==0)
            break;
        double temp;
        int cnt=0;
        for(int i=0; i<=n; i++)
            par[i]=i;
        for(int i=0; i<n; i++)
            cin >> cell[i].x >> cell[i].y >> cell[i].z >> cell[i].r;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                temp=dist(cell[i],cell[j])-cell[i].r-cell[j].r;
                cor[cnt].u=i;
                cor[cnt].v=j;
                if(temp>0)
                    cor[cnt].dis=temp;
                else
                    cor[cnt].dis=0;
                cnt++;
            }
        }
        sort(cor,cor+cnt,cmp);
        ans=0;
        for(int i=0; i<cnt; i++)
            unionset(i);
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}
