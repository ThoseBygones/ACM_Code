#include<iostream>
#include<cstring>
using namespace std;

int dp[125][125];

int main()
{
    int n;
    for(int i=1; i<=125; i++)
        dp[1][i]=dp[i][1]=1;
    for(int i=2; i<=120; i++)
    {
        for(int j=2; j<=120; j++)
        {
            if(j==i)
                dp[i][j]=dp[i][j-1]+1;
            else if(i<j)
                dp[i][j]=dp[i][i];
            else
                dp[i][j]=dp[i][j-1]+dp[i-j][j];
        }
    }
    while(cin >> n)
        cout << dp[n][n] << endl;
    return 0;
}
