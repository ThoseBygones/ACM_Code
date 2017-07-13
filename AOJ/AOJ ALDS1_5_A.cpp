#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[25];
int n;
bool flag;

void dfs(int val,int sum,int p,int mark)
{
    if(p==n+1)
        return ;
    if(sum==val)
    {
        flag=true;
        return ;
    }
    if(mark)
        sum+=a[p];
    dfs(val,sum,p+1,0);
    dfs(val,sum,p+1,1);
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int temp;
        flag=false;
        scanf("%d",&temp);
        dfs(temp,0,0,0);
        dfs(temp,0,0,1);
        if(flag)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
