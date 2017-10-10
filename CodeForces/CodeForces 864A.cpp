#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

set <int> s;
map <int,int> mp;
vector <int> ans;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int temp;
        scanf("%d",&temp);
        s.insert(temp);
        mp[temp]++;
    }
    if(s.size()!=2)
    {
        puts("NO");
        return 0;
    }
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
    {
        ans.push_back(*it);
        if(mp[*it]!=n/2)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    printf("%d %d\n",ans[0],ans[1]);
    return 0;
}
