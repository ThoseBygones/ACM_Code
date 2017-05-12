#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define LL long long
using namespace std;

#define MAXN 105

vector <LL> ans;
set <LL> a,b;   //ÐÐ¡¢ÁÐ
LL n,m;

int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        LL x,y;
        cin >> x >> y;
        a.insert(x);
        b.insert(y);
        ans.push_back((n-a.size())*(n-b.size()));
    }
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
