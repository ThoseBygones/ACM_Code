#include<cstdio>
using namespace std;

int w[11]= {1,2,4,10,20,40,100,200,400,1000,2000};
long long int dp[50050][15];
int main()
{
    double temp;
    int i,j,money;
    while(scanf("%lf",&temp)!=EOF&&temp!=0)
    {
        money=temp*20;
        for(i=0; i<=6000; i++)
            for(j=0; j<11; j++)
            {
                if(i-w[j]>0)
                    dp[i][j]=dp[i][j-1]+dp[i-w[j]][j];
                else if(i-w[j]==0)
                    dp[i][j]=dp[i][j-1]+1;
                else
                    dp[i][j]=dp[i][j-1];
            }
        printf("%6.2lf%17lld\n",temp,dp[money][10]);
    }
    return 0;
}
