#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 105

char str[MAXN];
int dp[2][MAXN];    //dp[0][i]��ʾCAPSLOCK��û��ʱҪ������������dp[1][i]��ʾ����ʱ

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
            if(str[i]>='a' && str[i]<='z')  //��ǰҪ����Сд��ĸ
            {
                dp[0][i]=min(dp[1][i-1]+2,dp[0][i-1]+1);    //ǰһ״̬��1.����������ٰ���ĸ��2.�ư���ֱ�Ӱ���ĸ������������״̬Ϊ���
                dp[1][i]=min(dp[1][i-1]+2,dp[0][i-1]+2);    //ǰһ״̬��1.��������shift�ٰ���ĸ��2.�ư�������ĸ�����ơ���������״̬Ϊ����
            }
            else if(str[i]>='A' && str[i]<='Z')  //��ǰҪ�����д��ĸ
            {
                dp[0][i]=min(dp[1][i-1]+2,dp[0][i-1]+2);    //ǰһ״̬��1.����������ĸ����ƣ�2.�ư�����shift�ٰ���ĸ������������״̬Ϊ���
                dp[1][i]=min(dp[1][i-1]+1,dp[0][i-1]+2);    //ǰһ״̬��1.������ֱ�Ӱ���ĸ��2.�ư��������ٰ���ĸ������������״̬Ϊ����
            }
        }
        printf("%d\n",min(dp[0][len],dp[1][len]+1));  //����������������������Ҫ���
    }
    return 0;
}
