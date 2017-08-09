#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

struct Fountain
{
    int b;
    int p;
    char c;
} f[MAXN];

vector <Fountain> coin;
vector <Fountain> diam;
int cb[MAXN];   //花费不同的coin能得到的最大beauty
int db[MAXN];   //花费不同的diamond能得到的最大beauty

bool cmp(Fountain x,Fountain y)
{
    if(x.p==y.p)
        return x.b>y.b;
    return x.p<y.p;
}

int main()
{
    int n,c,d;
    scanf("%d%d%d",&n,&c,&d);
    for(int i=1; i<=n; i++)
    {
        char temp[3];
        scanf("%d%d%s",&f[i].b,&f[i].p,temp);
        f[i].c=temp[0];
    }
    sort(f+1,f+1+n,cmp);
    for(int i=1; i<=n; i++)
    {
        if(f[i].c=='C' && f[i].p<=c)
        {
            coin.push_back(f[i]);
            cb[f[i].p]=max(cb[f[i].p],f[i].b);
        }
        else if(f[i].c=='D' && f[i].p<=d)
        {
            diam.push_back(f[i]);
            db[f[i].p]=max(db[f[i].p],f[i].b);
        }
    }
    for(int i=1; i<=c; i++)
        cb[i]=max(cb[i],cb[i-1]);
    for(int i=1; i<=d; i++)
        db[i]=max(db[i],db[i-1]);
    int ans=0;
    for(int i=coin.size()-1; i>=0; i--)
    {
        int temp=0;
        if(i>=1)
            temp=cb[min(coin[i-1].p,c-coin[i].p)];  //寻找花费最小coin能得到的次大beauty值
        temp=max(temp,db[d]);   //与花费diamond能得到的最大beauty值比较
        if(temp)
            ans=max(ans,temp+coin[i].b);
    }
    for(int i=diam.size()-1; i>=0; i--)
    {
        int temp=0;
        if(i>=1)
            temp=db[min(diam[i-1].p,d-diam[i].p)];  //寻找花费diamond能得到的次大beauty值
        temp=max(temp,cb[c]);   //与花费coin能得到的最大beauty值比较
        if(temp)
            ans=max(ans,temp+diam[i].b);
    }
    printf("%d\n",ans);
    return 0;
}
