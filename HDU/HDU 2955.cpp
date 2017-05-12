#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 10010

int m[MAXN];
double p[MAXN]; //��ץ�Ŀ�����
double dp[MAXM];    //��ĳ�����в���ץ����������

int main()
{
    int t,n;
    double pos;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%lf%d",&pos,&n);
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
        {
            scanf("%d%lf",&m[i],&p[i]);
            sum+=m[i];
        }
        dp[0]=1.0;
        for(int i=0; i<n; i++)
        {
            for(int j=sum; j>=m[i]; j--)
                dp[j]=max(dp[j],dp[j-m[i]]*(1.0-p[i])); //�������ץ�Ŀ�����
        }
        for(int i=sum; i>=0; i--)
        {
            if(dp[i]>=(1.0-pos))    //���ݲ���ץ�����������������������Ǯ�������ֵ
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
