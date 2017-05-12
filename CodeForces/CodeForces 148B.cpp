#include <iostream>
#include <cstdio>
using namespace std;

int vp,vd,t,f,c;

int main()
{
    while(~scanf("%d%d%d%d%d",&vp,&vd,&t,&f,&c))
    {
        if(vp>=vd)
            printf("0\n");
        else
        {
            int cnt=0;  //要使用的宝箱总量
            int u=vd-vp;
            double sum=0; //记录整个过程中公主走的路程
            sum+=1.0*vp*t;  //龙还未发现的时候
            sum+=1.0*vp*(sum/u);    //第一次龙追赶上公主时
            while(sum<c)
            {
                cnt++;  //丢一次宝箱
                sum+=1.0*vp*(f+sum/vd); //龙滚回去并待上t小时
                sum+=1.0*vp*(sum/u);    //龙又滚回来追公主
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
