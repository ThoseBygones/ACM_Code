#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 105

char str[MAXN];
int dp[2][MAXN];    //dp[0][i]表示CAPSLOCK灯没亮时要按的最多次数，dp[1][i]表示灯亮时

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str+1);
        int len=strlen(str+1);
        //cout << len << endl;
        dp[0][0]=0;
        dp[1][0]=1;
        for(int i=1; str[i]; i++)
        {
            if(str[i]>='a' && str[i]<='z')  //当前要输入小写字母
            {
                dp[0][i]=min(dp[1][i-1]+2,dp[0][i-1]+1);    //前一状态：1.灯亮，灭灯再按字母；2.灯暗，直接按字母。结束后最新状态为灭灯
                dp[1][i]=min(dp[1][i-1]+2,dp[0][i-1]+2);    //前一状态：1.灯亮，按shift再按字母；2.灯暗，按字母再亮灯。结束最新状态为亮灯
            }
            else if(str[i]>='A' && str[i]<='Z')  //当前要输入大写字母
            {
                dp[0][i]=min(dp[1][i-1]+2,dp[0][i-1]+2);    //前一状态：1.灯亮，按字母再灭灯；2.灯暗，按shift再按字母。结束后最新状态为灭灯
                dp[1][i]=min(dp[1][i-1]+1,dp[0][i-1]+2);    //前一状态：1.灯亮，直接按字母；2.灯暗，亮灯再按字母。结束后最新状态为亮灯
            }
        }
        printf("%d\n",min(dp[0][len],dp[1][len]+1));  //所有输入结束后如果灯亮还要灭灯
    }
    return 0;
}
