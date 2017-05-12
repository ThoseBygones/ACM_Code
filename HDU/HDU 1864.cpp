#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m[35];    //��i�ŷ�Ʊ�ܱ��������Ǯ��
int dp[3000010];    //��������Ҫ��������������Ҫ��ȷ��С�������λ��*100�����������������Ҫ30*1000*100
                    //dp[i]��ʾǰi�ŷ�Ʊ���Ա��������Ǯ��

int main()
{
    double q;
    int n;
    while(~scanf("%lf%d",&q,&n),n)
    {
        int sum=(int)(q*100);
        memset(m,0,sizeof(m));
        memset(dp,0,sizeof(dp));
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            int num;
            scanf("%d",&num);
            int a=0,b=0,c=0;
            char ch,temp;
            double p;
            bool flag=true;
            while(num--)
            {
                //scanf("%c%c%c%lf",&temp,&ch,&temp,&p);
                scanf(" %c:%lf",&ch,&p);
                int val=(int)(p*100);
                if(ch=='A' && a+val<=60000)
                    a+=val;
                else if(ch=='B' && b+val<=60000)
                    b+=val;
                else if(ch=='C' && c+val<=60000)
                    c+=val;
                else
                    flag=false;
            }
            if(a+b+c<=100000 && a<=60000 && b<=60000 && c<=60000 && flag)
                m[cnt++]=a+b+c;
        }
        for(int i=0; i<cnt; i++)
        {
            for(int j=sum; j>=m[i]; j--)
                dp[j]=max(dp[j],dp[j-m[i]]+m[i]);
        }
        printf("%.2lf\n",dp[sum]/100.00);
    }
    return 0;
}
