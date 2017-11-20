#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1005

vector <int> e[MAXN];

int x[MAXN],y[MAXN],r[MAXN];
int rot[MAXN];  //记录每个齿轮的旋转方向：1--顺时针，2--逆时针
int n;

bool checkconnect(int i,int j)
{
    if((r[i]+r[j])*(r[i]+r[j])==(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]))
        return true;
    return false;
}

bool dfs(int u,int r)
{
    rot[u]=r;
    for(int i=0; i<e[u].size(); i++)
    {
        int v=e[u][i];
        if(rot[v])
        {
            if(rot[u]==rot[v])
                return false;
            continue;
        }
        if(!dfs(v,r*(-1)))
            return false;
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d",&x[i],&y[i],&r[i]);
    memset(rot,0,sizeof(rot));
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(checkconnect(i,j))
            {
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
    }
    if(!dfs(0,1))
        puts("The input gear cannot move.");
    else if(!rot[n-1])
        puts("The input gear is not connected to the output gear. ");
    else
    {
        if(rot[0]!=rot[n-1])
            printf("-");
        int x=__gcd(r[0],r[n-1]);
        printf("%d:%d\n",r[0]/x,r[n-1]/x);
    }
    return 0;
}
