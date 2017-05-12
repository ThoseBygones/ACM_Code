#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000005
#define INF 0x3f3f3f3f

int a[MAXN];
int dp[MAXN];   //dp[j]��ʾ��j��Ԫ���ڵ�i�����������ֵ
int pre[MAXN];  //pre[j]��ʾ��j��Ԫ������һ�飨��i-1�飩���������ֵ

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=m; i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        int Max;
        for(int i=1; i<=n; i++) //ö��������
        {
            Max=-INF;
            for(int j=i; j<=m; j++) //ÿ��������������Ҫ��һ��Ԫ��
            {
                dp[j]=max(dp[j-1],pre[j-1])+a[j];
                pre[j-1]=Max;
                Max=max(dp[j],Max);
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}
