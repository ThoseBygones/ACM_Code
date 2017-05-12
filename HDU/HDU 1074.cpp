//状态压缩dp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

#define MAXN 1<<16
#define INF 1<<30

struct Node
{
    int id; //当前状态在完成作业全过程所经历的状态的编号
    int cost;   //到达当前状态花费的总时间
    int pre;    //上一个状态
    int lost;   //当前状态下损失的最少分数
} dp[MAXN]; //作业完成情况用二进制表示

struct Course
{
    char s[105];
    int d;
    int c;
} course[16];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        //memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
            scanf("%s%d%d",course[i].s,&course[i].d,&course[i].c);
        int tot=1<<n;   //所有状态
        for(int i=1; i<tot; i++)
        {
            dp[i].lost=INF;
            //cout << dp[i].lost << endl;
            for(int j=n-1; j>=0; j--)
            {
                int temp=1<<j;
                if(i&temp)  //状态i能通过状态完成第j项作业达到
                {
                    int past=i-temp;    //推出之前的状态
                    int lostsum=dp[past].cost+course[j].c-course[j].d;    //计算之前状态下补完成这项作业后总的扣除的分数
                    lostsum=max(0,lostsum); //扣除的总分数不可能小于零
                    //cout << lostsum << endl;
                    if(lostsum+dp[past].lost<dp[i].lost)
                    {
                        dp[i].lost=lostsum+dp[past].lost;
                        dp[i].id=j;
                        dp[i].pre=past;    //为达到目前状态应完成第j项作业
                        dp[i].cost=dp[past].cost+course[j].c;   //达到当前状态花费的总时间
                    }
                }
            }
        }
        int finalstatus=tot-1;  //最终状态应为所有作业都完成
        printf("%d\n",dp[finalstatus].lost);
        stack <int> s;
        int status=finalstatus;
        while(status)   //回溯法查找完成作业的全过程
        {
            s.push(dp[status].id);
            status=dp[status].pre;
        }
        while(!s.empty())
        {
            printf("%s\n",course[s.top()].s);
            s.pop();
        }
    }
    return 0;
}
