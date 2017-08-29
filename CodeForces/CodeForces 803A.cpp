#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int a[MAXN][MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(k>n*n)
    {
        puts("-1");
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i][j])
                continue;
            else
            {
                if(i==j && k)
                {
                    a[i][j]=1;
                    k--;
                    continue;
                }
                if(k>=2)
                {
                    a[i][j]=a[j][i]=1;
                    k-=2;
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<n; j++)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][n]);
    }
    return 0;
}
