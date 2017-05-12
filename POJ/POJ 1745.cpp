#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10005];
int dp[10005][105]; ///dp[i][j]Ϊǰi�����Ӽ������ֵ�Ƿ����j��ʵ����dp�����Ǹ�bool���飬��Ҳ������������ĵط���������
int n,k;

int mod(int x)  //����ȡ��
{
    x%=k;
    while(x<0)
        x+=k;
    return x;
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        dp[1][mod(a[1])]=1;
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<k; j++)  //����ģ�ⷽʽ
            {
                //dp[i][j]=dp[i-1][mod(j+a[i])] || dp[i-1][mod(j-a[i])];    //dp[i][j]��dp[i-1][[mod(j+a[i])]��dp[i-1][mod(j-a[i])]�ó�
                if(dp[i-1][j])  //dp[i-1][j]�Ƴ�dp[i][mod(j+a[i])]��dp[i][mod(j-a[i])]
                {
                    dp[i][mod(j+a[i])]=1;
                    dp[i][mod(j-a[i])]=1;
                }
            }
        }
        if(dp[n][0])
            printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
    return 0;
}
