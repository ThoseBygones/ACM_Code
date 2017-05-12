//״̬ѹ��dp
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
    int id; //��ǰ״̬�������ҵȫ������������״̬�ı��
    int cost;   //���ﵱǰ״̬���ѵ���ʱ��
    int pre;    //��һ��״̬
    int lost;   //��ǰ״̬����ʧ�����ٷ���
} dp[MAXN]; //��ҵ�������ö����Ʊ�ʾ

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
        int tot=1<<n;   //����״̬
        for(int i=1; i<tot; i++)
        {
            dp[i].lost=INF;
            //cout << dp[i].lost << endl;
            for(int j=n-1; j>=0; j--)
            {
                int temp=1<<j;
                if(i&temp)  //״̬i��ͨ��״̬��ɵ�j����ҵ�ﵽ
                {
                    int past=i-temp;    //�Ƴ�֮ǰ��״̬
                    int lostsum=dp[past].cost+course[j].c-course[j].d;    //����֮ǰ״̬�²����������ҵ���ܵĿ۳��ķ���
                    lostsum=max(0,lostsum); //�۳����ܷ���������С����
                    //cout << lostsum << endl;
                    if(lostsum+dp[past].lost<dp[i].lost)
                    {
                        dp[i].lost=lostsum+dp[past].lost;
                        dp[i].id=j;
                        dp[i].pre=past;    //Ϊ�ﵽĿǰ״̬Ӧ��ɵ�j����ҵ
                        dp[i].cost=dp[past].cost+course[j].c;   //�ﵽ��ǰ״̬���ѵ���ʱ��
                    }
                }
            }
        }
        int finalstatus=tot-1;  //����״̬ӦΪ������ҵ�����
        printf("%d\n",dp[finalstatus].lost);
        stack <int> s;
        int status=finalstatus;
        while(status)   //���ݷ����������ҵ��ȫ����
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
