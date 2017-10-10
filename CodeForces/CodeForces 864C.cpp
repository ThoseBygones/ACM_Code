#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int main()
{
    int a,b,f,k;
    scanf("%d%d%d%d",&a,&b,&f,&k);
    int cnt=0;
    int s=b-f;  //到达最近的加油站不加油以后还能走的距离
    for(int i=1; i<=k; i++)
    {
        if(s<0)
        {
            puts("-1");
            return 0;
        }
        if(i==k)
        {
            if(k&1) //去程
            {
                if(s<a-f)   //不够直接走到a点，这次就得加
                {
                    cnt++;
                    s=b;
                }
                if(s<a-f)   //加了油还到不了
                {
                    puts("-1");
                    return 0;
                }
            }
            else    //回程
            {
                if(s<f) //不够直接走到0点，这次就得加
                {
                    cnt++;
                    s=b;
                }
                if(s<f) //加了油还到不了
                {
                    puts("-1");
                    return 0;
                }
            }
        }
        else
        {
            if(i&1) //去程
            {
                if(s<2*(a-f))   //不够到a点回来再加油，这次就得加
                {
                    cnt++;
                    s=b-2*(a-f);
                }
                else    //不用加油，直接走回来再考虑
                    s-=2*(a-f);
            }
            else    //回程
            {
                if(s<2*f)   //不够到0点回来再加油，这次就得加
                {
                    cnt++;
                    s=b-2*f;
                }
                else    //不用加油，直接走回来再考虑
                    s-=2*f;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
