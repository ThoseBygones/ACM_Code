#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(x%i==0 && x/i<=n)    //1.ÿһ�е����ݶ�����һ�еĵ�һ�����ֵı�����Ӧ���ܱ����еĵ�һ������������2.ÿһ�е����ݶ���һ�����ֵ��Ӧ��С��������ֵ
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
