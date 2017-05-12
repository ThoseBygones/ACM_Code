#include <iostream>
#include <cstring>
using namespace std;

char str[100005];
int dp[100005];

int main()
{
    str[0]='0';
    cin >> str+1;
    int n;
    cin >> n;
    int len=strlen(str);
    dp[1]=0;
    for(int i=1; i<=len; i++)
    {
        if(str[i+1]==str[i])
            dp[i]=dp[i-1]+1;
        else
            dp[i]=dp[i-1];
    }
    while(n--)
    {
        int l,r;
        cin >> l >> r;
        int ans=dp[r-1]-dp[l-1];
        cout << ans << endl;
    }
    return 0;
}
