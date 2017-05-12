#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 105
#define INF 1e9

struct Points
{
    double x,y;
} p[MAXN*2];

double w[MAXN][MAXN],slack[MAXN],lx[MAXN],ly[MAXN];
int match[MAXN];
int visx[MAXN],visy[MAXN];
int nx,ny;//左右集合的点数
int ans[MAXN];

double dis(int i,int j)
{
    return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
}

bool find(int u)
{
    visx[u] = true;
    for(int i = 0; i<ny; i++)
    {
        if(visy[i]) continue;
        double t = lx[u]+ly[i]-w[u][i];
        if(fabs(t)<=1e-6)
        {
            visy[i] = true;
            if(match[i]==-1||find(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
        else slack[i] = min(slack[i],t);
    }
    return false;
}

bool update()
{
    double d =	INF;
    for(int i = 0; i<ny; i++) if(!visy[i]) d = min(d,slack[i]);
    if(d==INF) return false;//说明无法匹配了
    for(int i = 0; i<nx; i++)
    {
        if(visx[i]) lx[i]-=d,visx[i] = false;
    }
    for(int i = 0; i<ny; i++)
    {
        if(visy[i]) ly[i]+=d,visy[i] = false;
        else slack[i]-=d;
    }
    return true;
}

int km()
{
    memset(match,-1,sizeof(int)*ny);
    memset(ly,0,sizeof(int)*ny);
    for(int i = 0; i<nx; i++)
    {
        lx[i] = -INF;
        for(int j = 0; j<ny; j++) lx[i] = max(lx[i],w[i][j]);
    }
    for(int i = 0; i<nx; i++)
    {
        for(int j = 0; j<ny; j++) slack[j] = INF;
        memset(visx,0,sizeof(int)*nx);
        memset(visy,0,sizeof(int)*ny);
        while(!find(i))
            if(!update()) break;//无法匹配
    }
    int ans = 0;
    for(int i = 0; i<ny; i++)
    {
        if(match[i]!=-1) ans+=w[match[i]][i];
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    nx=ny=n;
    for(int i=0; i<2*n; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    memset(w,0,sizeof(w));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            w[i][j]=-dis(i,j+n);  //取距离的负值，这样求最短距离相当于求距离负值的最大值
    }
    int res=km();
    for(int i=0; i<n; i++)
        ans[match[i]]=i+1;
    for(int i=0; i<n; i++)
        printf("%d\n",ans[i]);
    return 0;
}
