//贪心
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,num,h[1000],mis[1000];
    while(~scanf("%d",&n))
    {
        num=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&h[i]);
            mis[i]=1;
        }
        for(i=1; i<n; ++i)
            for(j=0; j<i; ++j)
            {
                if(h[j]<=h[i]&&mis[j]+1>mis[i])
                    mis[i]=mis[j]+1;
                num=max(num,mis[i]);
            }
        printf("%d\n",num);
    }
    return 0;
}


//动态规划
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1005];

int main()
{
    int n,x,m;
    while(scanf("%d",&n)!=EOF&&n)
    {
        dp[1]=0;
        m=0;  //m代表最长递减序列个数
        //dp[i]代表第i个最长递减序列中当前状态的所含元素最小值
        for(int i=1; i<=n; i++)
        {
            int j;
            scanf("%d",&x);
            //将当前状态值与之前阶段值对比
            for(j=1; j<=m; j++)
            {
                //如果比某个历史阶段的值小，则覆盖，读取下一状态值
                if(x<=dp[j])
                {
                    dp[j]=x;
                    break;
                }
            }
            //如果当前状态值比之前阶段值都大，则新增序列
            //新增的序列最小元素值为当前状态值
            if(j>m)
                dp[++m]=x;
        }
        printf("%d\n",m);
    }
    return 0;
}
