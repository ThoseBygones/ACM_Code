//���ر���
//HDU 1059
//���⣺��ֵ�ֱ�Ϊ1,2,3,4,5,6����Ʒ�ĸ����ֱ�Ϊ a[1],a[2],...,a[6]
//���ܲ��ֳܷ����Ѽ�ֵ��ȵ�
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10];
int dp[120005]; //6*20000
int valsum,m;

void ZeroOnePack(int weight,int value)   //weightΪ���ã�valueΪ��ֵ
{
    for(int i=m; i>=weight; i--)
    {
        if(dp[i-weight]+value>dp[i])
            dp[i]=dp[i-weight]+value;
    }
}

void CompletePack(int weight,int value)
{
    for(int i=weight; i<=m; i++)
    {
        if(dp[i-weight]+value>dp[i])
            dp[i]=dp[i-weight]+value;
    }
}

void MultiplePack(int weight,int value,int amount)
{
    if(weight*amount>=m)
        CompletePack(weight,value);
    else
    {
        for(int k=1; k<amount;)
        {
            ZeroOnePack(k*weight,k*value);
            amount-=k;
            k<<=1;
        }
        ZeroOnePack(amount*weight,amount*value);
    }
}

int main()
{
    int kase=1;
    while(true)
    {
        int valsum=0;
        for(int i=1; i<=6; i++)
        {
            scanf("%d",&a[i]);
            valsum+=a[i]*i;
        }
        if(valsum==0)
            break;
        if(valsum%2)
        {
            printf("Collection #%d:\nCan't be divided.\n\n",kase++);
            continue;
        }
        else
        {
            m=valsum/2;
            memset(dp,0,sizeof(dp));
            for(int i=1; i<=6; i++)
                MultiplePack(i,i,a[i]);
        }
        if(dp[m]==m)
            printf("Collection #%d:\nCan be divided.\n\n",kase++);
        else
            printf("Collection #%d:\nCan't be divided.\n\n",kase++);
    }
    return 0;
}
