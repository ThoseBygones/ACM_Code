#include <bits/stdc++.h>
using namespace std;

map <string,int> vis,ban;
vector <string> ans;

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        string a,b;
        string fir,sec;
        cin >> a >> b;
        fir=a.substr(0,3);
        sec=a.substr(0,2)+b.substr(0,1);
        if(!vis[sec])   //先贪第二种取名法
        {
            vis[sec]=1;
            ans.push_back(sec);
        }
        else
        {
            if(vis[fir] || ban[fir])   //第一种名字有队已取或者按照规则禁止取
            {
                puts("NO");
                return 0;
            }
            else
            {
                vis[fir]=1;
                ans.push_back(fir);
            }
        }
        ban[fir]=1;
    }
    puts("YES");
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
