#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

map <char,char> mp;

string str1,str2;

int main()
{
    cin >> str1 >> str2;
    if(str1==str2)
    {
        puts("0");
        return 0;
    }
    for(int i=0; i<str1.size(); i++)
    {
        if(mp[str1[i]]!=str2[i] && mp[str1[i]]!=0)
        {
            puts("-1");
            return 0;
        }
        if(mp[str2[i]]!=str1[i] && mp[str2[i]]!=0)
        {
            puts("-1");
            return 0;
        }
        mp[str1[i]]=str2[i];
        mp[str2[i]]=str1[i];
    }
    int cnt=0;
    for(char i='a'; i<='z'; i++)
    {
        if(mp[i]!=0 && mp[i]!=i)
        {
            cnt++;
            mp[mp[i]]=0;
        }
    }
    cout << cnt <<endl;
    for(char i='a'; i<='z'; i++)
    {
        if(mp[i]!=0 && mp[i]!=i)
            cout << i << ' ' << mp[i] <<endl;
    }
    return 0;
}
