#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int tem[MAXN];

priority_queue <int, vector<int>, greater<int> > pq;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&tem[i]);
        if(tem[i]<0)
            cnt++;
    }
    if(cnt>k)
    {
        puts("-1");
        return 0;
    }
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        if(tem[i]<0 && tem[i-1]>=0) //贪心，先能换就换，保证肯定能安稳过冬
            sum+=2;
    }
    int s=0;
    for(int i=1; i<=n; i++)
    {
        if(tem[i]<0)
        {
           s=i;
           break;
        }
    }
    int con=0;    //每个高于零度的时间段持续的时间
    for(int i=1; i<=n; i++)
    {
        if(tem[i]>=0)   //当天温度高过零度时
        {
            if(tem[i-1]<0)  //前一天温度还低于零度
                con=1;
            else    //前一天温度也高于零度
                con++;
        }
        else    //当天温度低于零度
        {
            if(con)
            {
                pq.push(con);
                con=0;
            }
        }
    }
    //if(con)
    //    pq.push(con);   //特判最后一段
    int temp=cnt;   //能换就换时冬季轮胎使用天数
    while(!pq.empty())
    {
        if(temp+pq.top()<=k)    //若把最小的一段温度高于零度的时间段也换成使用冬季轮胎后使用冬季轮胎的总时间还未超出冬季轮胎的使用寿命
        {
            temp+=pq.top();
            pq.pop();
            sum-=2; //少换两次
        }
        else
            break;
    }
    if(temp+con<=k)
        sum--;  //特判最后一段，最后一段如果可以也只能少换一次
    printf("%d\n",sum);
    return 0;
}
