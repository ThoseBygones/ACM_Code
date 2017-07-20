#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int a[MAXN][MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    }
    bool flag=true;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==1)
                continue;
            bool mark=false;
            for(int k=0; k<n; k++)
            {
                for(int l=0; l<n; l++)
                {
                    if(a[i][j]==a[i][k]+a[l][j])
                    {
                        mark=true;
                        break;
                    }
                }
                if(mark)
                    break;
            }
            if(!mark)
            {
                flag=false;
                break;
            }
        }
        if(!flag)
            break;
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
