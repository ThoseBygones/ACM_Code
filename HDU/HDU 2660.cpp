#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int v[30],w[30],dp[1010][30],C,N,K,maxW;

int main()
{
    while(scanf("%d",&C)!=EOF)
    {
        while(C--)
        {
            memset(v,0,sizeof(v));
            memset(w,0,sizeof(w));
            memset(dp,0,sizeof(dp));
            cin>>N>>K;
            for(int i=1; i<=N; i++)
                cin>>v[i]>>w[i];
            cin>>maxW;
            for(int i=1; i<=N; i++)
                for(int j=maxW; j>=w[i]; j--)
                    for(int l=1; l<=K; l++)
                        dp[j][l]=max(dp[j][l],dp[j-w[i]][l-1]+v[i]);
            cout<<dp[maxW][K]<<endl;
        }
    }
    return 0;
}
