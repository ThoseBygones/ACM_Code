#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int g[30][30];
char s[MAXN];
int in[30],out[30];
bool sig[30]; //该字符是否为单独出现
bool vis[30];
bool flag;
string ans;

void dfs(int u)
{
    vis[u]=true;
    ans+=('a'+u);
    for(int v=0; v<26; v++)
    {
        if(g[u][v])
        {
            if(vis[v])
            {
                flag=false;
                return ;
            }
            dfs(v);
        }
    }
}

bool solve()
{
    for(int i=0; i<26; i++)
    {
        if(g[i][i])
            return false;
    }
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(g[i][j])
            {
                in[j]++;
                out[i]++;
            }
        }
    }
    for(int i=0; i<26; i++)
    {
        if(in[i]>1 || out[i]>1)
            return false;
    }
    memset(vis,0,sizeof(vis));
    for(int i=0; i<26; i++)
    {
        flag=true;
        if(!in[i] && out[i])
            dfs(i);
        if(!flag)
            return false;
        if(sig[i] && !in[i] && !out[i])
            ans+=('a'+i);
    }
    for(int i=0; i<26; i++)
    {
        if(in[i] || out[i])
        {
             if(!vis[i])
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(sig,false,sizeof(sig));
    for(int i=0; i<n; i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        for(int j=0; j<len-1; j++)
            g[s[j]-'a'][s[j+1]-'a']=1;
        if(len==1)
            sig[s[0]-'a']=true;
    }
    ans="";
    if(solve())
        cout << ans << endl;
    else
        cout << "NO" << endl;
    return 0;
}
