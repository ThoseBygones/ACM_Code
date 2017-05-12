#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 405
#define MAXM 40005

int sum[MAXM];  //�ﵽĳ���߶���Ҫ��ľ������
int dp[MAXM];   //ĳ���߶��Ƿ��ܴﵽ��
int k;

struct Blocks
{
    int h;
    int a;
    int c;
} b[MAXN];

bool cmp(Blocks x,Blocks y)
{
    return x.a<y.a;
}

int main()
{
    scanf("%d",&k);
    for(int i=1; i<=k; i++)
        scanf("%d%d%d",&b[i].h,&b[i].a,&b[i].c);
    sort(b+1,b+k+1,cmp);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int ans=0;
    for(int i=1; i<=k; i++)
    {
        memset(sum,0,sizeof(sum));
        for(int j=b[i].h; j<=b[i].a; j++)
        {
            if(!dp[j] && dp[j-b[i].h] && sum[j-b[i].h]+1<=b[i].c)  //����߶�֮ǰδ�ﵽ��������߶ȼ�ȥĳ��ľ��ĸ߶�֮ǰ�ܴﵽ�Ҹ���ľ������û��������
            {
                dp[j]=1;    //����߶ȱ����ʹ�
                sum[j]=sum[j-b[i].h]+1; //��¼ľ������
                ans=max(ans,j); //������߶�
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
