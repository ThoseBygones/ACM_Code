///给定一个有向图，每个点出度为1，各个边长度为1。求一个最小的k，使得对于每个点x，经过k长度到达y，从y出发经过k回到x。
///不能形成环直接pass，能形成的话分两种：奇环和偶环
///奇环中的点要满足题目要求（每个点x经过k长度到达y且从y出发经过k回到x）只有从它本身出发回到它自己才能满足，因此奇环长度即为k；
///偶环中的点要满足题目要求（每个点x经过k长度到达y且从y出发经过k回到x），形象的说只需将环从x点处切断（形成从以x为起点、x为终点的线段），该线段的中点即为满足条件的y点。因此偶环长度的一半即为k
///最后求一下这些k值的最小公倍数（因为要求满足所有k的最小t，这个t显然得是每个k的整数倍）
#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

int a[MAXN];
int vis[MAXN];
vector <int> cir;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int cnt;
    for(int i=1; i<=n; i++)
    {
        if(vis[i])
            continue;
        cnt=1;  //环内点的数量
        int s=i;    //记录环的起点
        int t=a[i]; //下一个点
        vis[s]=1;
        while(!vis[t])
        {
            vis[t]=1;
            t=a[t];
            cnt++;
        }
        //cout << s << "#" << t << endl;
        if(s!=t)    //起点终点不同，即不是环
        {
            puts("-1\n");
            return 0;
        }
        if(cnt>=2)  //值为1时无所谓
        {
            if(cnt%2==0)    //偶环除2
                cnt/=2;
            cir.push_back(cnt);
        }
    }
    int len=cir.size();
    int ans;
    if(len==0)  //若无大于等于2的环
        ans=1;
    else
        ans=cir[0];
    for(int i=1; i<len; i++)
    {
        int res=__gcd(ans,cir[i]);    //求最小公因数
        ans=ans*cir[i]/res; //求最大公倍数
    }
    printf("%d\n",ans);
    return 0;
}
