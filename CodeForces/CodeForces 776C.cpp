#include <bits/stdc++.h>
//#include <unordered_map>
#define LL long long
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 100005

int a[MAXN];
map <LL,LL> Hash; //前缀和为i的数其值是k的幂的个数
//unordered_map <LL,LL> Hash;   //会超时

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    LL ans=0;
    LL sum=0;
    Hash[0]=1;
    for(int i=1; i<=n; i++)
    {
        sum+=a[i];  //前缀和处理
        if(k==-1)   //k=-1时特殊处理，因为1和-1均为-1的m次幂
            ans+=Hash[sum-1]+Hash[sum+1];
        else
        {
            for(LL j=1; j<=1e18; j*=k)
            {
                ans+=Hash[sum-j];
                if(k==1)    //1的m次幂也为1，因此不必继续循环
                    break;
            }
        }
        Hash[sum]++;
    }
    printf("%I64d\n",ans);
    return 0;
}
