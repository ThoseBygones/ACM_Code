#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define MAXM 2005

struct Item
{
    int t,d,p;
    int id;
} a[MAXN];

int dp[MAXN][MAXM]; //第i个物品到j时间时能拿到的总价值
int pre[MAXN][MAXM];    //记录取物路径
vector <int> v;

bool cmp(const Item &x,const Item &y)   //按照物品生存时间从小到大排序
{
    return x.d<y.d;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].p);
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        for(int j=2000; j>=1; j--)  //正序遍历逆序遍历均可
        //for(int j=1; j<=2000; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=a[i].t && j<a[i].d)
            {
                if(dp[i][j]<dp[i-1][j-a[i].t]+a[i].p)
                {
                    dp[i][j]=dp[i-1][j-a[i].t]+a[i].p;
                    pre[i][j]=i;
                }
            }
        }
    }
    int ans=0;
    int sumt;
    for(int i=1; i<=2000; i++)
    {
        if(ans<dp[n][i])
        {
            ans=dp[n][i];
            sumt=i;
        }
    }
    printf("%d\n",ans);
    int pos=n;
    while(sumt>0 && pos>0)
    {
        if(pre[pos][sumt]>0)
            //s.push(a[pre[pos][sumt]].id);
            v.push_back(a[pre[pos][sumt]].id);  //不能使用栈来逆推（记录路径），会RE（爆栈）
        sumt-=a[pre[pos][sumt]].t;
        pos--;
    }
    /*
    printf("%d\n",s.size());
    bool flag=true;
    while(!s.empty())
    {
        if(flag)
        {
            printf("%d",s.top());
            s.pop();
            flag=false;
        }
        else
        {
            printf(" %d",s.top());
            s.pop();
        }
    }
    */
    printf("%d\n",v.size());
    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
    {
        if(i==0)
            printf("%d",v[i]);
        else
            printf(" %d",v[i]);
    }
    puts("");
    return 0;
}
