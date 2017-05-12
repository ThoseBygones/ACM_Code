//这是并查集很常见的一种题型。看起来好像用并查集无法做，但实际上可以转换成种类并查集
//对于A~B之间的数字之和为S，可以理解成B比A-1大S，即前B个元素之和比前A-1个元素之和大S
//接下来就可以按照常规的种类并查集做了
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 200005
using namespace std;

int par[MAXN],sum[MAXN];    //sum数组记录和
int n,m;
int ans;

int findset(int r)
{
    if(r!=par[r])
    {
        int temp=par[r];
        par[r]=findset(par[r]); //寻找根节点，并把该点的父节点指向根节点
        sum[r]+=sum[temp];  //累加寻找过程中的子段和
    }
    return par[r];
}

void mergeset(int x,int y,int s)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx==yy)  //若根节点相同
    {
        if(sum[y]-sum[x]!=s)    //若第x个数到第y个数的和（即前y个数的和与前x-1个数的和的差）与之前记录的矛盾，则发现一个错误的答案
        {
            ans++;
            return ;
        }
    }
    else if(xx>yy)
    {
        par[xx]=yy; //并到数值小的节点上
        sum[xx]=sum[y]-sum[x]-s;    //将串的和记录在数值大的节点上
    }
    else if(xx<yy)
    {
        par[yy]=xx; //并到数值小的节点上
        sum[yy]=sum[x]-sum[y]+s;    //将串的和记录在数值大的节点上
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<=n; i++)
        {
            par[i]=i;
            sum[i]=0;
        }
        ans=0;
        while(m--)
        {
            int a,b,s;
            scanf("%d%d%d",&a,&b,&s);
            a--;    //将a减去一，即维护a-1到b之间的数字串
            mergeset(a,b,s);
        }
        printf("%d\n",ans);
    }
    return 0;
}
