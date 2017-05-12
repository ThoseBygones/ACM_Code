#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 2005
#define INF 1e18

LL c[MAXN];    //ÿ����Ʒ�ļ۸�
LL t[MAXN];    //�ۻ�Ա����ÿ����Ʒ��ʱ��
LL dp[MAXN];    //���ڵ�i����Ʒ���Ѿ�������j����Ʒ����Ҫ����С��ֵ
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%I64d%I64d",&t[i],&c[i]);
    for(int i=0; i<=n; i++)
        dp[i]=INF;
    dp[0]=0LL;
    for(int i=1; i<=n; i++)
    {
        for(int j=n; j>=1; j--)
        {
            if(j<t[i]+1)
                dp[j]=min(dp[j],c[i]);
            else
                dp[j]=min(dp[j],dp[j-1-t[i]]+c[i]);
        }
    }
    printf("%I64d\n",dp[n]);
    return 0;
}
