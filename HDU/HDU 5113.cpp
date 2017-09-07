#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define LL long long
#define PII pair
#define MP make_pair
#define PB push_back

int mp[10][10];
int c[30];
int n,m,k;
bool flag;

void dfs(int x,int y,int blank) //blank为剩下的未涂色的格子数
{
    if(blank==0)
        flag=true;
    if(flag)
        return ;
    for(int i=1; i<=k; i++)
    {
        if(c[i]>(blank+1)/2)    //剩余格子数的一半大于任何一种颜色还可以涂的数量，则不可能顺利着色
            return ;
    }
    for(int i=1; i<=k; i++)
    {
        if(c[i])
        {
            if(mp[x-1][y]!=i && mp[x][y-1]!=i)  //该格子的颜色要与该格子左侧和上方的格子颜色不同
            {
                mp[x][y]=i;
                c[i]--;
                if(y==m)
                    dfs(x+1,1,blank-1);
                else
                    dfs(x,y+1,blank-1);
                if(flag)    //如果这样的方案能顺利涂色，则不需要还原现场，直接结束
                    return ;
                c[i]++;
            }
        }
    }
}

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(mp,0,sizeof(mp));
        flag=false;
        for(int i=1; i<=k; i++)
            scanf("%d",&c[i]);
        dfs(1,1,n*m);
        printf("Case #%d:\n",kase++);
        if(flag)
        {
            puts("YES");
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(j==m)
                        printf("%d\n",mp[i][j]);
                    else
                        printf("%d ",mp[i][j]);
                }
            }
        }
        else
            puts("NO");
    }
}
