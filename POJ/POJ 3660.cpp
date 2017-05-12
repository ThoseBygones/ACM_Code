#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
//#define MAXM 4505
using namespace std;

int cow[MAXN][MAXN];
int n,m;

void Floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(cow[i][k] && cow[k][j])
                    cow[i][j]=1;
                //printf("%d\n",cow[i][j]);
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    cow[i][j]=1;
                else
                    cow[i][j]=cow[j][i]=0;
            }
        }
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            cow[u][v]=1;
        }
        Floyd();
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            int cnt=0;
            for(int j=1; j<=n; j++)
            {
                if(cow[i][j] || cow[j][i])
                    cnt++;
            }
            //printf("%d\n",cnt);
            if(cnt==n)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
