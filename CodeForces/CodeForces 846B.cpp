#include <bits/stdc++.h>
using namespace std;

#define MAXN 55

int t[MAXN];
int n,k,m;
int sum;

int dfs(int id,int cursum)
{
    if(id>n)
        return 0;
    int ans=0;
    if(cursum>=sum)  //finish a whole task
        ans=max(ans,k+1+dfs(id+1,cursum-sum));
    int tot=0;
    for(int i=1; i<=k; i++) //do the subtask that cost less
    {
        if(cursum>=(n-id+1)*t[i])
        {
            tot+=n-id+1;
            if(i==k)    //extra score for finish a whole task
                tot+=n-id+1;
            cursum-=(n-id+1)*t[i];
        }
        else
        {
            tot+=cursum/t[i];
            if(i==k)
                tot+=cursum/t[i];   //extra score for finish a whole task
            cursum-=(cursum/t[i])*t[i];
            //break;    //can break if no time left (add this sentence or not will be both ok
        }
    }
    return max(tot,ans);
}

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    sum=0;
    for(int i=1; i<=k; i++)
    {
        scanf("%d",&t[i]);
        sum+=t[i];
    }
    sort(t+1,t+1+k);
    int ans=dfs(1,m);
    printf("%d\n",ans);
    return 0;
}
