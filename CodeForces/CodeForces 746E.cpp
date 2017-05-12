#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 200005

int a[MAXN];
map <int,int> vis;  //记录写着某个数字的卡牌是不是已经拥有
int cnt[2];  //记录奇数偶数卡牌的数量
vector <int> v;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(vis[a[i]] || cnt[(a[i]&1)]==n/2) //如果卡牌重复或奇数（偶数）卡牌数量已满，则记录下来以备之后做变换
            v.push_back(i);
        else
        {
            vis[a[i]]=1;
            cnt[(a[i]&1)]++;
        }
    }
    int cnum=0;  //做出变动的卡牌的数量
    for(int i=1; i<=m; i++)
    {
        if(cnum==v.size())
            break;
        if(!vis[i]) //某个编号的卡牌还没拥有
        {
            if(cnt[(i&1)]<n/2)  //该卡牌对应奇数（偶数）的卡牌数量未满
            {
                cnt[(i&1)]++;
                a[v[cnum]]=i;  //替换该卡牌
                cnum++;
            }
        }
    }
    if(cnum<v.size())
        puts("-1");
    else
    {
        printf("%d\n",cnum);
        for(int i=1; i<n; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
