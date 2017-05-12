#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1005

int a[MAXN][MAXN];

int main()
{
    int t;
    int r,c;
    int n;
    scanf("%d",&t);
    int kase=1;
    while(t--)
    {
        scanf("%d%d",&r,&c);
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        int sum1=0;
        int sum2=0;
        for(int i=0; i<r; i++)
        {
            int cnt=0;
            for(int j=0; j<c; j++)
            {
                if(a[i][j]==0)
                    cnt++;
                if(a[i][j]==1 || j==c-1)
                {
                    if(cnt==1)
                    {
                        sum1+=1;
                        sum2+=1;
                    }
                    else
                    {
                        if(cnt%2==1)
                            sum1+=cnt/2+1;
                        else
                            sum1+=cnt/2;
                        if(cnt%3==0)
                            sum2+=cnt/3;
                        else
                            sum2+=cnt/3+1;
                    }
                    cnt=0;
                }
            }
        }
        printf("Case #%d: %d %d\n",kase++,sum1,sum2);
    }
    return 0;
}
