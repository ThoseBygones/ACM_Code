#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 1e9
#define MAXN 100005

int n;
LL a[MAXN]; //�ۼ�����ʱ��
LL dp[MAXN];    //ǰi�����е���С����

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%I64d",a+i);
    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1]+20;   //ÿ������һ�ΰ�������Ʊ��Ҫ�ཻ20
        int x=upper_bound(a,a+n+1,a[i]-90)-a-1;  //�ҵ���ӽ�90���ӵ�һ�����л���
        dp[i]=min(dp[i],dp[x]+50);  //��֮ǰ�õ������ŷ�ʽ��ȫ��Ʊ��ѡ����͵ļ۸�
        int y=upper_bound(a,a+n+1,a[i]-1440)-a-1;   ////�ҵ���ӽ�1440���ӵ�һ�����л���
        dp[i]=min(dp[i],dp[y]+120); //��֮ǰ�õ������ŷ�ʽ��ȫ��Ʊ��ѡ����͵ļ۸�
        printf("%I64d\n",dp[i]-dp[i-1]);   //�������µ�һ�����л�Ҫ��������Ǯ
    }
}
