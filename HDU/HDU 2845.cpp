#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 200005

int dpR[MAXN];  //对每行进行dp，每行取前j个数能得到的最大豆子数
int dpC[MAXN];  //对每列进行dp，每列取前i个数能得到的最大豆子数

int main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
                scanf("%d",&dpR[j]);
            for(int j=2; j<=n; j++)
                dpR[j]=max(dpR[j-2]+dpR[j],dpR[j-1]);
            dpC[i]=dpR[n];
        }
        for(int i=2; i<=m; i++)
            dpC[i]=max(dpC[i-2]+dpC[i],dpC[i-1]);
        printf("%d\n",dpC[m]);
    }
    return 0;
}
