#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 505

char puz[MAXN][MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",puz[i]);
    int u=n-1;  //最上
    int d=0;    //最下
    int l=m-1;  //最左
    int r=0;    //最右
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(puz[i][j]=='X')
            {
                if(i<u)
                    u=i;
                if(i>d)
                    d=i;
                if(j<l)
                    l=j;
                if(j>r)
                    r=j;
            }
        }
    }
    bool flag=true;
    for(int i=u; i<=d; i++)
    {
        for(int j=l; j<=r; j++)
        {
            if(puz[i][j]=='.')
            {
                flag=false;
                break;
            }
        }
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
