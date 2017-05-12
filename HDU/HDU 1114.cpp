#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[100010],p[505],w[505];

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int e,f,N;
        cin>>e>>f;
        cin>>N;
        for(int i=0; i<N; i++)
            cin>>p[i]>>w[i];
        for(int i=0; i<=f-e; i++)
            dp[i]=1000001;
        dp[0]=0;
        for(int i=0; i<N; i++)
        {
            for(int j=w[i]; j<=f-e; j++)
            {
                dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
            }
        }
        if(dp[f-e]==1000001)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f-e]);
    }
}
