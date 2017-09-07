#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

map <int,int> mp;   //map模拟前缀和

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        mp[l]++;
        mp[r+1]--;
    }
    int sum=0;
    for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        sum+=it->second;
        if(sum>2)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
