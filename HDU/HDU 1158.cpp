#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 15
#define MAXM 1005
#define INF 0x3f3f3f3f

int num[MAXN];  //ÿ����������Ҫ��Ա����
int dp[MAXN][MAXM]; //ǰi���£�������i���£���Ӷj��Ա����Ҫ���ѵ���Сֵ

int main()
{
    int n;
    int hire,salary,fire;
    while(~scanf("%d",&n),n)
    {
        scanf("%d%d%d",&hire,&salary,&fire);
        int maxnum=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            maxnum=max(maxnum,num[i]);
        }
        for(int i=num[1]; i<=maxnum; i++)
            dp[1][i]=(hire+salary)*i;
        for(int i=2; i<=n; i++)
        {
            for(int j=num[i]; j<=maxnum; j++)   //ö�ٵ��¹���Ա����
            {
                int Minsum=INF;
                for(int k=num[i-1]; k<=maxnum; k++) //ö���ϸ��¹�ӶԱ����
                {
                    if(k<j) //�ϸ��±�����¹�Ӷ��Ա����
                        Minsum=min(Minsum,dp[i-1][k]+(j-k)*hire+j*salary);
                    else    //�ϸ��±�����¹�Ӷ��Ա����
                        Minsum=min(Minsum,dp[i-1][k]+(k-j)*fire+j*salary);
                }
                dp[i][j]=Minsum;
            }
        }
        int ans=INF;
        for(int i=num[n]; i<=maxnum; i++)
            ans=min(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
