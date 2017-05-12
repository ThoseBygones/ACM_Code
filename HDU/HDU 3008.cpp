#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

int a[MAXN],b[MAXN];
int dp[MAXN][MAXN]; //��ʾ��i�빥����ʣ��jħ��ֵʱ���ĵ�boss��Ѫ��

int main()
{
    int n,t,q;
    while(~scanf("%d%d%d",&n,&t,&q))
    {
        if(n==0 && t==0 && q==0)
            break;
        for(int i=1; i<=n; i++)
            scanf("%d%d",&a[i],&b[i]);
        a[0]=0; //��ͨ�����ķ�0ħ��ֵ
        b[0]=1; //��ͨ��������boss��Ѫ��
        memset(dp,0,sizeof(dp));
        dp[0][100]=0;   //��ʼ״̬
        int round;  //Ӣ���ܼ�ֵ�ʱ��
        if(100%q)
            round=100/q+1;
        else
            round=100/q;
        bool ok=false;
        for(int i=1; i<=round; i++) //ö��ս���е�ÿһ��
        {
            for(int j=0; j<=100; j++)   //ö��ÿ�ֿ��ܵ�ħ��ʣ����
            {
                int temp=min(j+t,100);
                for(int k=0; k<=n; k++) //ö�����й�����ʽ
                {
                    if(100-a[k]>=j)
                        dp[i][temp]=max(dp[i][temp],dp[i-1][j+a[k]]+b[k]);
                }
                if(dp[i][temp]>=100)
                {
                    printf("%d\n",i);
                    ok=true;
                    break;
                }
            }
            if(ok)
                break;
        }
        if(!ok)
            puts("My god");
    }
    return 0;
}
