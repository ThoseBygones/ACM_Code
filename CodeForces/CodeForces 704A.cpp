#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005

int vis[MAXN];  //该消息是否被读过

queue <pair<int,int> > q[MAXN]; //first--消息是哪个app发出的，second--消息是总第几个消息

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    int cnt=0;  //消息编号
    int ans=0;  //未读消息总数
    int p=1;  //所有消息按照编号，第一条未被读的消息编号
    while(m--)
    {
        int op,val;
        scanf("%d%d",&op,&val);
        if(op==1)
        {
            q[val].push(make_pair(val,++cnt));
            ans++;
        }
        else if(op==2)
        {
            while(!q[val].empty())
            {
                int temp=q[val].front().second;
                if(!vis[temp])  //该消息未被读过，则未读总数-1
                    ans--;
                vis[temp]=1;    //该消息被读过
                q[val].pop();
            }
        }
        else
        {
            for(int i=p; i<=min(val,cnt); i++)
            {
                if(!vis[i])
                    ans--;
                vis[i]=1;
            }
            p=max(p,val);
        }
        printf("%d\n",ans);
    }
    return 0;
}
