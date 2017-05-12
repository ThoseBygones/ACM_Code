#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[105],b[105];
int dp[105][105];   //����i������ɱ��jֻ���Ժ��ܻ�õ���ྭ��ֵ
int n,m,k,s;

//��ά���ñ���

int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&k,&s))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=k; i++)
            scanf("%d%d",&a[i],&b[i]);
        for(int i=1; i<=k; i++)
        {
            for(int j=b[i]; j<=m; j++)  //���ܴ�m->b[i]��������Խ����Ӱ��
            {
                for(int l=1; l<=s; l++)
                    dp[j][l]=max(dp[j][l],dp[j-b[i]][l-1]+a[i]);
            }
        }
        if(dp[m][s]>=n) //������ɱ�ַ�ʽ�ܹ���õľ���ֵ������Ҫ
        {
            for(int i=1; i<=m; i++)
            {
                if(dp[i][s]>=n) //���Ͷȱ���Խ��Խ��
                {
                    printf("%d\n",m-i);
                    break;
                }
            }
        }
        else
            puts("-1");
    }
    return 0;
}
