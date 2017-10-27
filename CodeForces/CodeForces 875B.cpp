#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005

int p[MAXN];
int vis[MAXN];
vector <int> ans;

int main()
{
    int n;
    scanf("%d",&n);
    ans.push_back(1);
    int cnt=1;
    int ed=n;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&p[i]);
        vis[p[i]]=1;
        cnt++;
        while(vis[ed])
        {
            ed--;
            cnt--;
        }
        ans.push_back(cnt);
    }
    for(int i=0; i<ans.size(); i++)
    {
        if(i)
            printf(" %d",ans[i]);
        else
            printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
