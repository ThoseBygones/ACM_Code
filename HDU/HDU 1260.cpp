#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[2005],ta[2005],tb[2005];

int main()
{
    int n,k;
    cin >> n;
    while(n--)
    {
        cin >> k;
        for(int i=1;i<=k;i++)
            cin >> ta[i];
        for(int i=2;i<=k;i++)
            cin >> tb[i];
        dp[1]=ta[1];
        for(int i=2;i<=k;i++)
            dp[i]=min(dp[i-1]+ta[i],dp[i-2]+tb[i]);
        int hh=dp[k]/3600;
        int mm=dp[k]%3600/60;
        int ss=dp[k]%60;
        printf("%02d:%02d:%02d",hh+8,mm,ss);
        if(hh+8>=12)
            cout << " pm" << endl;
        else
            cout << " am" << endl;
    }
}
