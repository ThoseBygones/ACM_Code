#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int k[MAXN],f[MAXN];
int n,m;

bool check(int val)    //检查这种分配方式是否能符合现有的条件
{
    for(int i=1; i<=m; i++)
    {
        if((k[i]+val-1)/val!=f[i])
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
        scanf("%d%d",&k[i],&f[i]);
    int ans=-1;
    for(int i=1; i<=101; i++)   //枚举每层的flat数量
    {
        if(check(i))
        {
            if(ans==-1) //记录第一种符合条件的分配方案
                ans=(n+i-1)/i;
            else
            {
                if((n+i-1)/i!=ans)  //分配方案与之前的方案不同，则表明多解
                {
                    ans=-1;
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
