//̰��
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,num,h[1000],mis[1000];
    while(~scanf("%d",&n))
    {
        num=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&h[i]);
            mis[i]=1;
        }
        for(i=1; i<n; ++i)
            for(j=0; j<i; ++j)
            {
                if(h[j]<=h[i]&&mis[j]+1>mis[i])
                    mis[i]=mis[j]+1;
                num=max(num,mis[i]);
            }
        printf("%d\n",num);
    }
    return 0;
}


//��̬�滮
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1005];

int main()
{
    int n,x,m;
    while(scanf("%d",&n)!=EOF&&n)
    {
        dp[1]=0;
        m=0;  //m������ݼ����и���
        //dp[i]�����i����ݼ������е�ǰ״̬������Ԫ����Сֵ
        for(int i=1; i<=n; i++)
        {
            int j;
            scanf("%d",&x);
            //����ǰ״ֵ̬��֮ǰ�׶�ֵ�Ա�
            for(j=1; j<=m; j++)
            {
                //�����ĳ����ʷ�׶ε�ֵС���򸲸ǣ���ȡ��һ״ֵ̬
                if(x<=dp[j])
                {
                    dp[j]=x;
                    break;
                }
            }
            //�����ǰ״ֵ̬��֮ǰ�׶�ֵ��������������
            //������������СԪ��ֵΪ��ǰ״ֵ̬
            if(j>m)
                dp[++m]=x;
        }
        printf("%d\n",m);
    }
    return 0;
}
