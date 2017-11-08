#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int a[5][10];
int vis[105];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=6; j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=6; j++)
        {
            vis[a[i][j]]=1;
            for(int k=1; k<=n; k++)
            {
                if(k!=i)
                {
                    for(int h=1; h<=6; h++)
                        vis[a[i][j]*10+a[k][h]]=1;
                }
            }
        }
    }
    for(int i=1; i<=100; i++)
    {
        if(!vis[i])
        {
            printf("%d\n",i-1);
            break;
        }
    }
    return 0;
}
