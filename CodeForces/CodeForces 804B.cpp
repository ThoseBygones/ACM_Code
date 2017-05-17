#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main()
{
    string s;
    cin >> s;
    int cnt=0;  //b的个数
    int ans=0;  //操作次数
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]=='b')
            cnt++;
        else
        {
            ans=(ans+cnt)%MOD;
            cnt=(cnt<<1)%MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}
