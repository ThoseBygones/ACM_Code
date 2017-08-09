#include <bits/stdc++.h>
using namespace std;

#define MAXN 8005
#define INF 0x3f3f3f3f

char s[MAXN];
int f[MAXN];    //next数组
int dp[MAXN];   //dp[i]表示字符串子串[1,i]的最小压缩表示

//kmp求循环节
void getFail(char* p,int len)
{
    f[0] = f[1] = 0;
    for(int i = 1; i<len; i++)
    {
        int j = f[i];
        while(j&&p[i]!=p[j]) j = f[j];
        f[i+1] = p[i]==p[j]?j+1:0;
    }
}

int getNumLen(int val)
{
    int cnt=0;
    while(val)
    {
        val/=10;
        cnt++;
    }
    return cnt;
}

int main()
{
    scanf("%s",s);
    int n=strlen(s);
    for(int i=n-1; i>=0; i--)
    {
        dp[i]=INF;
        getFail(s+i,n-i);
        for(int j=n; j>=i; j--)  //枚举子串
        {
            int temp=j-i+1-f[j-i+1]; //求出当前子串最短的循环节长度
            if((j-i+1)%temp)    //除了循环节还包含别的字符
                dp[i]=min(dp[i],dp[j+1]+(j-i+1)+1);
            else
                dp[i]=min(dp[i],dp[j+1]+getNumLen((j-i+1)/temp)+temp);
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}
