#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

vector <int> ans[MAXN];

int main()
{
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0; i<n; i++)
    {
        int temp;
        scanf("%d",&temp);
        ans[temp%m].push_back(temp);
    }
    bool flag=false;
    for(int i=0; i<m; i++)
    {
        if(ans[i].size()>=k)
        {
            puts("Yes");
            flag=true;
            for(int j=0; j<k; j++)
            {
                if(j)
                    printf(" %d",ans[i][j]);
                else
                    printf("%d",ans[i][j]);
            }
            puts("");
            break;
        }
    }
    if(!flag)
        puts("No");
    return 0;
}
