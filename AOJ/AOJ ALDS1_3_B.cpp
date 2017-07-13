#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

queue < pair<string,int> > que;

int main()
{
    ios::sync_with_stdio(false);
    int n,q,t;
    cin >> n >> q;
    string name;
    for(int i=1; i<=n; i++)
    {
        cin >> name >> t;
        que.push(make_pair(name,t));
    }
    int sumt=0;
    pair <string,int> u;
    while(!que.empty())
    {
        u=que.front();
        que.pop();
        int temp=min(u.second,q);
        u.second-=temp;
        sumt+=temp;
        if(u.second>0)
            que.push(u);
        else
            cout << u.first << " " << sumt << endl;
    }
    return 0;
}
