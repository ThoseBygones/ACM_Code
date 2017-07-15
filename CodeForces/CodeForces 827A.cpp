#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

string s[MAXN];
vector <pair<int,int> > v;

int main()
{
    int n,k;
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s[i] >> k;
        for(int j=0; j<k; j++)
        {
            int x;
            cin >> x;
            v.push_back(make_pair(x,i));
        }
    }
    sort(v.begin(),v.end());
    string ans;
    int pos=1;  //当前处理到的下标的指针
    for(int i=0; i<v.size(); i++)
    {
        while(v[i].first>pos)
        {
            ans+="a";
            pos++;
        }
        for(int j=pos-v[i].first; j<s[v[i].second].length(); j++) //重复的字符跳过
        {
            ans+=s[v[i].second][j];
            pos++;
        }
    }
    cout << ans << endl;
    return 0;
}
