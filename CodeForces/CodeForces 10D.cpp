#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 505
using namespace std;

int a[MAXN],b[MAXN],dp[MAXN],pre[MAXN]; //pre数组记录上升序列前一个元素的位置
int n,m;

void print(int num) //回溯法利用pre数组找到LCIS序列前几个元素
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
            if(a[i]==b[j])  //相等
            {
                dp[j]=dp[temp]+1;   //记录为LCIS的编号
                pre[j]=temp;    //记录前一个元素的下标
            }
            else if(a[i]>b[j] && dp[j]>dp[temp])    //上升的时候
                temp=j; //记录位置
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
