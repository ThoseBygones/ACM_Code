#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005
#define MAXM 100005

int w[MAXN],cnt[MAXN];
int dp[MAXM];
int n,m;

void ZeroOnePack(int value,int weight)  //01����
{
    for(int i=m; i>=weight; i--)
    {
        dp[i]=max(dp[i],dp[i-weight]+value);
    }
}

void CompletePack(int value,int weight) //��ȫ����
{
    for(int i=weight; i<=m; i++)
    {
        dp[i]=max(dp[i],dp[i-weight]+value);
    }
}

void MultiPack(int value,int weight,int cnt)
{
    if(weight*cnt>=m)  //ת��Ϊ��ȫ����
        CompletePack(value,weight);
    else    //ת��Ϊ01����
    {
        int k=1;
        while(k<=cnt) //�������Ż�
        {
            ZeroOnePack(value*k,weight*k);
            cnt-=k;
            k*=2;
        }
        for(int i=m; i>=cnt*weight; i--)
            dp[i]=max(dp[i],dp[i-cnt*weight]+cnt*value);
    }
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            scanf("%d%d",&cnt[i],&w[i]);
        for(int i=1; i<=n; i++)
            MultiPack(w[i],w[i],cnt[i]);
        printf("%d\n",dp[m]);
    }
    return 0;
}
