#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int v[50050],dp[50050],n,m,sum;

int main()
{
    cin>>n;
    while(n--)
    {
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));
        cin>>m;
        sum=0;
        for(int i=1;i<=m;i++)
        {
            cin>>v[i];
            sum+=v[i];
        }

        for(int i=1;i<=m;i++)
            for(int j=sum/2;j>=v[i];j--)
                dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        int dif=sum-2*dp[sum/2];
        cout<<dif<<endl;
    }
}
