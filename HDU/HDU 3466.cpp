#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Merchant
{
    int p;
    int q;
    int v;
} mc[505];

int dp[5005];
int n,m;

bool cmp(Merchant a,Merchant b)
{
    return a.q-a.p<b.q-b.p;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++)
            scanf("%d%d%d",&mc[i].p,&mc[i].q,&mc[i].v);
        memset(dp,0,sizeof(dp));
        sort(mc,mc+n,cmp);
        for(int i=0 ;i<n; i++)
        {
            for(int j=m; j>=mc[i].q; j--)
                dp[j]=max(dp[j],dp[j-mc[i].p]+mc[i].v); //�����е�j-mc[i].p��������Ҫ��֤״̬ת�Ʒ����޺�Ч�ԣ������mc[i].q-mc[i].p��С��������j-mc[i].pҪ��j���㣩
            /*for(int j=0; j<=m; j++)
                cout << dp[j] << " ";
            cout << endl;
            */
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}

/*
5 10
3 10 5
2 7 4
1 6 6
5 6 9
2 3 5
*/
//20
/*
5 10
2 7 4
1 6 6
3 10 5
5 6 9
2 2 5
*/
//24
