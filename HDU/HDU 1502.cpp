//DP+高精度（大数）
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char dp[65][65][65][105];   //dp[i][j][k][h]表示i个a，j个b，k个c

void add(char a[],char b[])
{
    int lena=strlen(a);
    int lenb=strlen(b);
    int len=min(lena,lenb);
    int ca=0;   //进位标志
    int i=0;
    for(i=0; i<len; i++)
    {
        int num=a[i]-'0'+b[i]-'0'+ca;
        a[i]=num%10+'0';
        ca=num/10;
    }
    while(i<lena)
    {
        int num=a[i]-'0'+ca;
        a[i]=num%10+'0';
        ca=num/10;
        i++;
    }
    while(i<lenb)
    {
        int num=b[i]-'0'+ca;
        a[i]=num%10+'0';
        ca=num/10;
        i++;
    }
    if(ca)
    {
        a[i]=ca+'0';
        a[i+1]='\0';
    }
    else
        a[i]='\0';
}

int main()
{
    int n;
    memset(dp,'\0',sizeof(dp));
    dp[0][0][0][0]='1';
    dp[0][0][0][1]='\0';
    for(int i=1; i<=60; i++)
    {
        for(int j=0; j<=i; j++)
        {
            for(int k=0; k<=j; k++)
            {
                if(i-1>=j)  //i和j数量不相等
                    add(dp[i][j][k],dp[i-1][j][k]);
                if(j-1>=k)  //j和k数量不相等
                    add(dp[i][j][k],dp[i][j-1][k]);
                if(k-1>=0)
                    add(dp[i][j][k],dp[i][j][k-1]);
            }
        }
    }
    while(~scanf("%d",&n))
    {
        if(n==0)
            puts("0");
        else
        {
            for(int i=strlen(dp[n][n][n])-1; i>=0; i--)
                printf("%c",dp[n][n][n][i]);
            puts("");
        }
        puts("");
    }
    return 0;
}
