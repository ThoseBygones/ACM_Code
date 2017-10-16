#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 500005 //每根棒子有2个端点

int fa[MAXN];
int degree[MAXN];   //结点的度
int colorcnt;
char s[15],t[15];

class Trie
{
public:
#define CHAR_NUM 26 //10--只有数字，26--只有大写/小写字母，52--大小写字母都有，62--数字+大小写字母
#define MAXNODE 500005

    struct node
    {
        int next[CHAR_NUM];
        int val;
        bool flag;  //字符串结束标记
        void init()
        {
            memset(next,-1,sizeof(next));
            val = 0;
            flag = false;
        }
    } nd[MAXNODE];

    int root;
    int cnt;

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

    int insert(char *s)
    {
        int temp = root;
        for(int i = 0; s[i]; i++)
        {
            int pos = s[i]-'a';
            //int pos = s[i]-'0';
            if(nd[temp].next[pos]==-1) nd[temp].next[pos] = newnode();
            temp = nd[temp].next[pos];
        }
        if(!nd[temp].flag)
        {
            nd[temp].flag=true;
            nd[temp].val=++colorcnt;
        }
        return nd[temp].val;
    }

    int find(char *s)
    {
        int temp = root;
        for(int i = 0; s[i]; i++)
        {
            int pos = s[i]-'a';
            //int pos = s[i]-'0';
            if(nd[temp].next[pos]==-1)
            {
                return 0;
            }
            else
                temp = nd[temp].next[pos];
        }
        return nd[temp].val;
    }
} trie;

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

void unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
        fa[xx]=yy;
}

int main()
{
    for(int i=1; i<MAXN; i++)
        fa[i]=i;
    colorcnt=0;
    trie.init();
    while(~scanf("%s%s",s,t))
    {
        int u=trie.insert(s);
        int v=trie.insert(t);
        degree[u]++;
        degree[v]++;
        unionset(u,v);
    }
    int root=findset(1);    //找到所有点的祖先
    int cnt=0;  //度数为奇数的结点数
    for(int i=1; i<=colorcnt; i++)
    {
        if(degree[i]&1)
            cnt++;
        if(cnt>2 || findset(i)!=root)   //图不连通或者图中没有欧拉通路
        {
            puts("Impossible");
            return 0;
        }
    }
    if(cnt==1)
        puts("Impossible");
    else
        puts("Possible");
    return 0;
}
