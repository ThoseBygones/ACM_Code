#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 105

int img[MAXN][MAXN];
int ans[MAXN][MAXN];
int dx[]= {-1,-1,-1,0,0,0,1,1,1};
int dy[]= {-1,0,1,-1,0,1,-1,0,1};

int main()
{
    int n,m,k;
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            scanf("%d",&img[i][j]);
    }
    int sum;
    for(int h=1; h<=k; h++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                sum=0;
                for(int d=0; d<9; d++)
                {
                    int nx=i+dx[d];
                    int ny=j+dy[d];
                    if(nx<=0)
                        nx=n;
                    if(nx>n)
                        nx=1;
                    if(ny<=0)
                        ny=m;
                    if(ny>m)
                        ny=1;
                    sum+=img[nx][ny];
                }
                ans[i][j]=sum;
            }
        }
        memcpy(img,ans,sizeof(img));
    }
    set <int> s;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            s.insert(img[i][j]);
    }
    printf("%d\n",s.size());
    return 0;
}
