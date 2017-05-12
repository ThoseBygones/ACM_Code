//���仯����... �Ҿ�Ȼû�뵽...
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 205

char a[MAXN],b[MAXN];
char c[MAXN*2];
int dp[MAXN][MAXN];

int dfs(int i,int j,int k)  //i--a�����±꣬j--b�����±꣬k--c�����±�
{
    if(dp[i][j])
        return dp[i][j];
    if(c[k]=='\0')
        return 1;   //��ʾ���ʹ����±������������ƥ��
    dp[i][j]=-1;    //��ʾ���±걻���ʹ�����û�и��κ�һ����ƥ��ɹ�
    if(a[i]==c[k])
        dp[i][j]=dfs(i+1,j,k+1);
    if(b[j]==c[k] && dp[i][j]!=1)
        dp[i][j]=dfs(i,j+1,k+1);
    //printf("%d %d %d\n",i,j,dp[i][j]);
    return dp[i][j];
}

int main()
{
    int t;
    int kase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s%s",a,b,c);
        memset(dp,0,sizeof(dp));    //��ʾ���±�û�б����ʹ�
        if(dfs(0,0,0)==1)
            printf("Data set %d: yes\n",kase++);
        else
            printf("Data set %d: no\n",kase++);
    }
    return 0;
}
