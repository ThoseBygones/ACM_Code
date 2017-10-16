#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool vis[500005];
bool flag;

class Trie
{
public:
#define CHAR_NUM 28 //10--只有数字，26--只有大写/小写字母，52--大小写字母都有，62--数字+大小写字母
#define MAXNODE 500005

    struct node
    {
        int next[CHAR_NUM];
        char ch;
        void init()
        {
            memset(next,-1,sizeof(next));
            ch = '$';
        }
    } nd[MAXNODE];

    int root;
    int cnt;
    vector <int> g[MAXNODE];

    void init()
    {
        cnt = 0;
        root = newnode();
    }

    int newnode()
    {
        nd[cnt].init();
        return cnt++;
    }

    int getIndex(char c)
    {
        if(c=='?')
            return 26;
        else if(c=='*')
            return 27;
        else
            return c-'a';
    }

    void insert(char *s,int v)
    {
        int u = root;
        for(int i = 0; s[i]; i++)
        {
            int pos = getIndex(s[i]);
            if(nd[u].next[pos]==-1)
            {
                nd[u].next[pos] = newnode();
                u = nd[u].next[pos];
                nd[u].ch = s[i];
            }
            else
                u = nd[u].next[pos];
        }
        g[u].push_back(v);
    }

    void dfs(char *s,int id,int u)
    {
        if(s[id]=='\0')
        {
            for(int i=0; i<g[u].size(); i++)
            {
                int v = g[u][i];
                flag = vis[v] = true;
            }
            if(nd[u].next[27]!=-1)
                dfs(s,id,nd[u].next[27]);
            return ;
        }
        int pos = getIndex(s[id]);
        if(nd[u].next[pos]!=-1)
            dfs(s,id+1,nd[u].next[pos]);
        if(nd[u].next[26]!=-1)
        {
            //printf("%d !26\n",u);
            //cout << id << endl;
            dfs(s,id+1,nd[u].next[26]);
        }
        if(nd[u].next[27]!=-1)
        {
            dfs(s,id+1,nd[u].next[27]);
            dfs(s,id,nd[u].next[27]);
        }
        if(nd[u].ch=='*')
            dfs(s,id+1,u);
    }
} trie;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    trie.init();
    for(int i=0; i<n; i++)
    {
        char w[30];
        scanf("%s",w);
        trie.insert(w,i);
    }
    /*
    for(int i=0; i<4; i++)
    {
        cout << trie.nd[i].ch << endl;
        for(int j=0; j<28; j++)
            printf("%d ",trie.nd[i].next[j]);
        puts("");
    }
    */
    while(m--)
    {
        char w[30];
        scanf("%s",w);
        flag=false;
        memset(vis,0,sizeof(vis));
        trie.dfs(w,0,0);
        if(!flag)
        {
            puts("Not match");
            continue;
        }
        for(int i=0; i<n; i++)
        {
            if(vis[i])
            {
                if(flag)
                {
                    printf("%d",i);
                    flag=false;
                }
                else
                    printf(" %d",i);
            }
        }
        puts("");
    }
    return 0;
}
