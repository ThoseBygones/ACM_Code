#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

char s[MAXN],t[MAXN];
vector <int> temp;
vector <int> ans;
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    scanf("%s",t);
    int Min=INF;
    for(int i=0; i<=m-n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(s[j]!=t[i+j])
                temp.push_back(j+1);
        }
        if(temp.size()<Min)
        {
            ans=temp;
            Min=temp.size();
        }
        temp.clear();
    }
    printf("%d\n",Min);
    for(int i=0; i<ans.size(); i++)
        printf("%d ",ans[i]);
    puts(" ");
    return 0;
}
