#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

char s1[MAXN],s2[MAXN];
int dp[MAXN][MAXN];
int match[MAXN][MAXN];

void preMatch()
{
    match['A']['A']=match['C']['C']=match['G']['G']=match['T']['T']=5;
    match['A']['C']=match['C']['A']=match['A']['T']=match['T']['A']=match[' ']['T']=match['T'][' ']=-1;
    match['A']['G']=match['G']['A']=match['C']['T']=match['T']['C']=match['G']['T']=match['T']['G']=match[' ']['G']=match['G'][' ']=-2;
    match['C']['G']=match['G']['C']=match[' ']['A']=match['A'][' ']=-3;
    match[' ']['C']=match['C'][' ']=-4;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int len1,len2;
        scanf("%d %s",&len1,s1+1);
        scanf("%d %s",&len2,s2+1);
        memset(dp,0,sizeof(dp));
        preMatch();
        for(int i=1; i<=len1; i++)
            dp[i][0]=dp[i-1][0]+match[s1[i]][' '];
        for(int j=1; j<=len2; j++)
            dp[0][j]=dp[0][j-1]+match[' '][s2[j]];
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                dp[i][j]=max(dp[i-1][j]+match[s1[i]][' '],dp[i][j-1]+match[' '][s2[j]]);
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+match[s1[i]][s2[j]]);
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
