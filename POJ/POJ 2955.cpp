#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

char s[MAXN];
int dp[MAXN][MAXN]; //dp[i][j]：区间下标i到j之间匹配的括号数量

bool match(char x,char y)
{
    if(x=='(' && y==')')
        return true;
    if(x=='[' && y==']')
        return true;
    return false;
}

int main()
{
    while(~scanf("%s",s))
    {
        if(s[0]=='e')
            break;
        int len=strlen(s);
        for(int i=0; i<len; i++)
        {
            dp[i][i]=0;
            if(match(s[i],s[i+1]))
                dp[i][i+1]=2;
            else
                dp[i][i+1]=0;
        }
        for(int k=2; k<len; k++)    //注意这里k从2开始枚举，否则后面的dp[i+1][i+k-1]会出现前一维下标大于后一维下标的情况（虽然也能AC）
        {
            for(int i=0; i+k<len; i++)
            {
                dp[i][i+k]=0;   //假设区间内没有括号匹配
                if(match(s[i],s[i+k]))
                    dp[i][i+k]=dp[i+1][i+k-1]+2;    //首尾匹配，则相当于去掉首尾后的区间的最大值+2
                for(int j=i; j<i+k; j++)
                    dp[i][i+k]=max(dp[i][i+k],dp[i][j]+dp[j+1][i+k]); //枚举不同的区间划分能得到的最大括号匹配数
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}
