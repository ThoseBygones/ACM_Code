#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 1005

struct Mouse
{
    int w;
    int s;
    int id;
} m[MAXN];

int dp[MAXN];
int pre[MAXN];  //记录前驱的数组（倒序记录），以便之后回溯查找
//vector <int> res;
int ans[MAXN];

bool cmp(Mouse a,Mouse b)
{
    if(a.w==b.w)
        return a.s>b.s;
    return a.w<b.w;
}

int main()
{
    int cnt=1;
    while(~scanf("%d%d",&m[cnt].w,&m[cnt].s))
    {
        dp[cnt]=1;
        pre[cnt]=0;
        m[cnt].id=cnt;
        cnt++;
    }
    cnt--;
    sort(m+1,m+cnt+1,cmp);
    int maxlen=0;  //最长子序列的长度
    int p;  //最长子序列最后一个元素的下标
    for(int i=1; i<=cnt; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(m[i].w>m[j].w && m[i].s<m[j].s && dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                pre[i]=j;
                if(dp[i]>maxlen)
                {
                    maxlen=dp[i];
                    p=i;
                }
            }
        }
    }
    int temp=p;
    int tot=0;
    while(temp)
    {
        //res.push_back(temp);
        ans[tot++]=temp;
        temp=pre[temp];
    }
    //printf("%d\n",res.size());
    printf("%d\n",tot);
    //for(int i=res.size()-1; i>=0; i--)
    //    printf("%d\n",m[res[i]].id);
    while(tot)
    {
        tot--;
        printf("%d\n",m[ans[tot]].id);
    }
    return 0;
}
