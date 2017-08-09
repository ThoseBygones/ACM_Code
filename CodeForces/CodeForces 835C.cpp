#include <bits/stdc++.h>
using namespace std;

#define MAXN 205
#define LL long long

int sky[MAXN][MAXN][15];
int n,q,c;

int main()
{
    scanf("%d%d%d",&n,&q,&c);
    for(int i=0; i<n; i++)
    {
        int x,y,s;
        scanf("%d%d%d",&x,&y,&s);
        sky[x][y][s]++;

    }

    //预处理求前缀和
    for(int k=0; k<=c; k++)
    {
        for(int i=1; i<=100; i++)
        {
            for(int j=1; j<=100; j++)
                sky[i][j][k]+=sky[i-1][j][k]+sky[i][j-1][k]-sky[i-1][j-1][k];
        }
    }

    while(q--)
    {
        int ans=0;
        int t,x1,x2,y1,y2;
        scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        for(int k=0; k<=c; k++)
            ans+=(sky[x2][y2][k]-sky[x1-1][y2][k]-sky[x2][y1-1][k]+sky[x1-1][y1-1][k])*((k+t)%(c+1));   //这里一定要先取模再乘，否则会出现负数
        printf("%d\n",ans);
    }
    return 0;
}
