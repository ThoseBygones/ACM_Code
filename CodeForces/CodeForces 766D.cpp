#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005

int par[MAXN];
int oppo[MAXN]; //与该单词关系相反的一个单词
int n,m,q;

map <string,int> word;

int findset(int r)
{
    if(r!=par[r])
        return par[r]=findset(par[r]);
    return r;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++)
    {
        string str;
        cin >> str;
        word[str]=i;
        par[i]=i;
        oppo[i]=0;
    }
    while(m--)
    {
        int t;
        string x,y;
        cin >> t >> x >> y;
        int u=findset(word[x]);
        int v=findset(word[y]); //找两个单词所对应点的根
        int ou=findset(oppo[u]);
        int ov=findset(oppo[v]);    //找两个单词与其相反的单词所对应点的根
        if(t==1)
        {
            if(u==ov || v==ou)
                puts("NO");
            else
            {
                puts("YES");
                par[u]=v;
                if(ou && ov)
                    par[ou]=ov;
                if(ou)
                    oppo[v]=ou;
                if(ov)
                    oppo[u]=ov;
            }
        }
        else
        {
            if(u==v)
                puts("NO");
            else
            {
                puts("YES");
                if(ou)
                    par[v]=ou;
                else
                    oppo[u]=v;
                if(ov)
                    par[u]=ov;
                else
                    oppo[v]=u;
            }
        }
    }
    while(q--)
    {
        string a,b;
        cin >> a >> b;
        int u=findset(word[a]);
        int v=findset(word[b]);
        int ou=findset(oppo[u]);
        int ov=findset(oppo[v]);
        if(u==v)
            puts("1");
        else
        {
            if(u==ov && v==ou)
                puts("2");
            else
                puts("3");
        }
    }
    return 0;
}
