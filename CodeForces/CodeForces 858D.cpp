#include <bits/stdc++.h>
using namespace std;

#define MAXN 70005

map <string,int> mp;
string ans[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for(int i=1; i<=n; i++)
    {
        cin >> s;
        for(int j=0; j<9; j++)
        {
            for(int k=1; j+k<=9; k++)
            {
                string temp=s.substr(j,k);
                if(!mp[temp] || mp[temp]==i)
                    mp[temp]=i;
                else
                    mp[temp]=-1;
            }
        }
    }
    /*
    for(int i=1; i<=n; i++)
        cout << ans[i].size() << endl;
    */
    for(map<string,int>::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second!=-1)
        {
            if(ans[it->second].size()==0)
                ans[it->second]=it->first;
            else
            {
                if(ans[it->second].size()>it->first.size())
                    ans[it->second]=it->first;
            }
        }
    }
    for(int i=1; i<=n; i++)
        cout << ans[i] << endl;
    return 0;
}
