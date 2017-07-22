#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int grid[MAXN][MAXN];
vector <int> r,c;
int n,m;
int sum;

void makeRow()
{
    for(int i=1; i<=n; i++)
    {
        int Min=INF;
        for(int j=1; j<=m; j++)
            Min=min(Min,grid[i][j]);
        for(int j=1; j<=m; j++)
            grid[i][j]-=Min;
        sum-=Min*m;
        for(int k=1; k<=Min; k++)
            r.push_back(i);
    }
}

void makeCol()
{
    for(int j=1; j<=m; j++)
    {
        int Min=INF;
        for(int i=1; i<=n; i++)
            Min=min(Min,grid[i][j]);
        for(int i=1; i<=n; i++)
            grid[i][j]-=Min;
        sum-=Min*n;
        for(int k=1; k<=Min; k++)
            c.push_back(j);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&grid[i][j]);
            sum+=grid[i][j];
        }
    }
    if(n>m)
    {
        makeCol();
        makeRow();
    }
    else
    {
        makeRow();
        makeCol();
    }
    if(sum!=0)
        puts("-1");
    else
    {
        printf("%d\n",r.size()+c.size());
        for(int i=0; i<r.size(); i++)
            printf("row %d\n",r[i]);
        for(int i=0; i<c.size(); i++)
            printf("col %d\n",c[i]);
    }
    return 0;
}
