#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1005

int main()
{
    int n,w;
    cin >> n >> w;
    double maxhappy=0.0;
    double rate=1.0;    //�õ��ܽ���ĸ���
    double temp=0.0;    //ÿһ�ֵ��Ҹ�ָ��
    int safemoney=0;  //�ܱ�֤�õ���Ǯ��
    for(int i=1; i<=n; i++)
    {
        string s;
        double p;
        int curmoney;
        cin >> s >> p >> curmoney;
        temp+=rate*(1.0-p)*log(1.0+1.0*safemoney/w); //�ܵ��Ҹ���
        rate*=p;   //�ܸ���
        maxhappy=max(maxhappy,temp+rate*log(1.0+1.0*curmoney/w));  //����Ҹ���
        if(s=="safe")
            safemoney=curmoney;
    }
    double ans=(exp(maxhappy)-1.0)*w;
    printf("$%.2f\n",ans);
    return 0;
}
