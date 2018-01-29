#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int a[MAXN];
int id[MAXN];   //房间id
int pre[MAXN];  //上次访问这个房间的时间

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int cnt=1;
    memset(id,0,sizeof(id));
    memset(pre,0,sizeof(pre));
    for(int i=1; i<=n; i++)
    {
        int t=a[i];
        if(pre[id[t]]==a[i])
        {
            pre[id[t]]=i;   //更新最近访问的时间
            id[i]=id[t];    //确定现在所在的房间号
        }
        else
        {
            id[i]=++cnt;    //这是个新房间
            pre[id[i]]=i;   //更新最近访问时间
        }
    }
    printf("%d\n",cnt);
    return 0;
}
