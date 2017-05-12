#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 100005

int w[MAXN],cnt[MAXN];
int dp[MAXM];
int n,m;

void MultiPack(int v,int w,int c)
{
    if(w*c>=m)  //ת��Ϊ��ȫ����
    {
        for(int i=w; i<=m; i++)
            dp[i]=max(dp[i],dp[i-w]+v);
    }
    else    //ת��Ϊ01����
    {
        int k=1;
        while(k<=c) //�������Ż�����Ϊ�������Ų���ѡ������i����Ʒ���ܿ��Ա�ʾ�����ɸ�2^k����Ʒ�ĺ͡�������ÿ����Ʒ���O(log(V/c[i]))����Ʒ��������13���Բ��1 2 4 6
        {
            for(int i=m; i>=k*w; i--)
                dp[i]=max(dp[i],dp[i-k*w]+k*v);
            c-=k;
            k*=2;
        }
        for(int i=m; i>=c*w; i--)
            dp[i]=max(dp[i],dp[i-c*w]+c*v);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
            scanf("%d",&w[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&cnt[i]);
        for(int i=0; i<=n; i++)
            MultiPack(w[i],w[i],cnt[i]);
        int sum=0;
        for(int i=1; i<=m; i++)
        {
            if(dp[i]==i)
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}


//ģ���
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 100005

int w[MAXN],cnt[MAXN];
int dp[MAXM];
int cash,n;

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
    while(~scanf("%d%d",&cash,&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
            scanf("%d",&w[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&cnt[i]);
        for(int i=0; i<=n; i++)
            MultiPack(w[i],w[i],cnt[i]);
        int sum=0;
        /*for(int i=1; i<=m; i++)
        {
            if(dp[i]==i)
                sum++;
        }*/
        printf("%d\n",dp[n]);
    }
    return 0;
}
