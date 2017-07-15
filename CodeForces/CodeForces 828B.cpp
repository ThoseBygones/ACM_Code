#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

char mat[MAXN][MAXN];

int main()
{
    int n,m;
    int xh,xl,yl,yr;
    int ans=0;
    scanf("%d%d",&n,&m);
    xh=INF,xl=-1,yl=INF,yr=-1;
    for(int i=0; i<n; i++)
    {
        scanf("%s",mat[i]);
        for(int j=0; j<m; j++)
        {
            if(mat[i][j]=='B')
            {
                xh=min(xh,i);
                xl=max(xl,i);
                yl=min(yl,j);
                yr=max(yr,j);
                ans++;
            }
        }
    }
    if(xh==INF)
        puts("1");
    else
    {
        int len=max(xl-xh,yr-yl)+1;
        //cout << len << endl;
        if(len>m || len>n)
            puts("-1");
        else
            printf("%d\n",len*len-ans);
    }
    return 0;
}
