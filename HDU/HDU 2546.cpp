#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int v[MAXN];    //�˵ļ۸�
int dp[MAXN];

int main()
{
    int n;
    int left;   //�������
    while(~scanf("%d",&n),n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            scanf("%d",&v[i]);
        scanf("%d",&left);
        if(left<5)
        {
            printf("%d\n",left);
            continue;
        }
        sort(v+1,v+n+1);
        for(int i=1; i<n; i++)  //�����Ǹ��˲�����dp����Ϊ���ֻҪ����Ǯ��>=5������������Ĳ�һ����ʹ���������С
        {
            for(int j=left-5; j>=v[i]; j--) //����5Ԫʱ�޷����ѣ��൱��dpֻ��Ҫ5~1000
                dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
        printf("%d\n",left-dp[left-5]-v[n]);    //����ʣ��Ǯ
    }
    return 0;
}
