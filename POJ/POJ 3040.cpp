//关键是如何寻找最优策略。
//对于面值小于c的硬币，我们先考虑一个c的方案。要使用的周数最多我们应该就要使钱的利用率最大。
//也就是说损失的钱最少：尽量不要超过c太多，在不超过c的情况下对于大面值和小面值的优先使用大面值的。
//因为小面值的组合可得到大面值的(整除关系)，留下小面值的给后面的组合最优的可能性越大。
//如这种策略下没凑够c的话就找一个最小的面额，使得组合值大于c。(使损失值最小)
//正确性证明：因为大的是小的倍数，所以大的放进去不超额一定要放进去。
//因为小的不管怎么取，在超过c之前一定会凑成这个大的面额，那么用大的代替一定更优。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 25
#define INF 0x3f3f3f3f

struct Coin
{
    int v;  //面值
    int b;  //数量
} a[MAXN];

int cnt[MAXN];  //记录当前取法第i种面值取的数量

bool cmp(Coin a,Coin b)
{
    return a.v<b.v;
}

int main()
{
    int n,c;
    while(~scanf("%d%d",&n,&c))
    {
        int ans=0;
        for(int i=0; i<n; i++)
            scanf("%d%d",&a[i].v,&a[i].b);
        sort(a,a+n,cmp);
        for(int i=n-1; i>=0; i--)    //第一步，从大到小把大于C的都取走
        {
            if(a[i].v>c)
            {
                ans+=a[i].b;
                a[i].b=0;
            }
        }
        while(true) //每次循环都在找一次当前最优取法，直到剩下的总金额小于C元
        {
            bool flag=false;
            int temp=c;
            memset(cnt,0,sizeof(cnt));
            for(int i=n-1; i>=0; i--)   //第二步，从大到小取，先不超过C
            {
                if(a[i].b)
                {
                    int num=temp/a[i].v;
                    num=min(num,a[i].b);
                    temp-=num*a[i].v;
                    cnt[i]=num;
                    if(temp==0)
                    {
                        flag=true;
                        break;
                    }
                }
            }
            if(temp)
            {
                for(int i=0; i<n; i++)  //第三步，从小到大取，超过C
                {
                    if(a[i].b>cnt[i])   //数量还够还能取
                    {
                        while(a[i].b>cnt[i])
                        {
                            temp-=a[i].v;
                            cnt[i]++;
                            if(temp<=0)
                            {
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(flag)    //凑到要求的值，结束
                        break;
                }
            }
            if(!flag)
                break;
            int num=INF;
            for(int i=0; i<n; i++)
            {
                if(cnt[i])  //找到当前取法的能取的总次数
                    num=min(num,a[i].b/cnt[i]);
            }
            ans+=num;
            for(int i=0; i<n; i++)
            {
                if(cnt[i])
                    a[i].b-=num*cnt[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
