#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 505
using namespace std;

int a[MAXN],b[MAXN],dp[MAXN],pre[MAXN]; //pre�����¼��������ǰһ��Ԫ�ص�λ��
int n,m;

void print(int num) //���ݷ�����pre�����ҵ�LCIS����ǰ����Ԫ��
{
    if(!num)
        return ;
    print(pre[num]);
    if(pre[num])
        cout << " ";
    cout << b[num];
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    cin >> m;
    for(int i=1; i<=m; i++)
        cin >> b[i];
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        int temp=0;
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])  //���
            {
                dp[j]=dp[temp]+1;   //��¼ΪLCIS�ı��
                pre[j]=temp;    //��¼ǰһ��Ԫ�ص��±�
            }
            else if(a[i]>b[j] && dp[j]>dp[temp])    //������ʱ��
                temp=j; //��¼λ��
        }
    }
    int cnt=max_element(dp,dp+m+1)-dp;
    cout << dp[cnt] << endl;
    if(cnt)
    {
        print(cnt);
        cout << endl;
    }
    return 0;
}
