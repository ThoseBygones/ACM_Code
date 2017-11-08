#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define LL long long
#define PB push_back

int t[MAXN],q[MAXN];
vector <int> ans;

int main()
{
    int n,a,b,c,d,start,len;
    scanf("%d%d%d%d%d%d%d",&n,&a,&b,&c,&d,&start,&len);
    for(int i=0; i<n; i++)
        scanf("%d%d",&t[i],&q[i]);
    ans.PB(-1);
    LL cur=0;
    LL Min=0;
    LL sum=start;
    for(int i=0; i<n; i++)
        ans.PB(t[i]);
    int p=0;
    for(int i=0; i<n; i++)
    {
        while(p<n && t[p]-t[i]<len) //某个时间点的事项会受到talk show的影响
        {
            if(q[p])
                cur+=c;
            else
                cur-=d;
            Min=min(Min,cur);
            p++;
        }
        if(sum+Min>=0)  //始终大于0
        {
            printf("%d\n",ans[i]+1);
            return 0;
        }
        if(q[i])    //还原现场
        {
            cur-=c;
            Min-=c;
            sum+=a;
        }
        else
        {
            cur+=d;
            Min+=d;
            sum-=b;
        }
        if(sum<0)   //始终有小于0的情况
        {
            puts("-1");
            return 0;
        }
    }
    printf("%d\n",ans[n]+1);
    return 0;
}
