#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n,want[MAXN],left[MAXN],right[MAXN];    //设第一个人拿的是编号1~want[i]号的勋章，则将左区间记为1~want[i]，右区间为(want[i]+1)~n

bool enough(int m)  //left,right数组仅记录每个人在左右区间取的勋章数即可
{
    int x=want[1];
    int y=m-want[1];
    left[1]=x;
    right[1]=0;
    for(int i=2; i<=n; i++) //除第一个人拿的勋章编号已经定下
    {
        if(i%2) //编号为奇数的人尽量拿右区间的勋章
        {
            right[i]=min(y-right[i-1],want[i]); //若只取右区间内的勋章已经够满足需求则不需要再从左区间补充
            left[i]=want[i]-right[i];
        }
        else    //编号为偶数的人尽量拿左区间的勋章
        {
            left[i]=min(x-left[i-1],want[i]);   //若只取左区间内的勋章已经够满足需求则不需要再从右区间补充
            right[i]=want[i]-left[i];
        }
    }
    if(left[n]==0)  //最后一个守卫取的勋章编号与第一个守卫不冲突（因为第一个守卫取的勋章全部属于做区间内，所以最后一个守卫只要不需要从左区间内取勋章）即能判断勋章数量符合题目要求
        return true;
    return false;
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&want[i]);
        if(n==1)    //n=1时直接输出这个守卫想要的勋章种类的数量
        {
            printf("%d\n",want[1]);
            continue;
        }
        want[n+1]=want[1];  //将第一个守卫想要的勋章种类的数量存入第n+1个数组中，起到构造环的作用
        int l=0,r=0;
        for(int i=1; i<=n; i++)
            l=max(l,want[i]+want[i+1]); //左边界为相邻两个人想要的勋章种类的数量之和的最大值
        if(n%2) //若守卫人数不是偶数，则特别处理
        {
            for(int i=1; i<=n; i++)
                r=max(r,want[i]*3); //右边界为某个人想要的勋章种类的数量*3
            while(l<=r) //二分法求需要的勋章种类的数量的最小值
            {
                int mid=(l+r)/2;
                if(enough(mid))
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}
