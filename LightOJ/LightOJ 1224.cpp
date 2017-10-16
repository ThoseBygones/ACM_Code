#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

map <char,int> mp;

class Trie
{
public:
#define CHAR_NUM 4 //10--只有数字，26--只有大写/小写字母，52--大小写字母都有，62--数字+大小写字母
#define MAXNODE 2500005

    struct node
    {
        int next[CHAR_NUM];
        int val;
        void init()
        {
            memset(next,-1,sizeof(next));
            val = 0;
        }
    } nd[MAXNODE];

    int root;
    int cnt;
    int ans;
    int depth;

    void init()
    {
        ans = 0;
        cnt = 0;
        root = newnode();
    }

    int newnode()
    {
        nd[cnt].init();
        return cnt++;
    }

    void insert(char *s)
    {
        depth = 0;
        int temp = root;
        for(int i = 0; s[i]; i++)
        {
            depth++;
            int pos=mp[s[i]];
            //int pos = s[i]-'a';
            //int pos = s[i]-'0';
            if(nd[temp].next[pos]==-1) nd[temp].next[pos] = newnode();
            temp = nd[temp].next[pos];
            nd[temp].val++;
            ans = max(ans,nd[temp].val*depth);
        }
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

char s[55];

int main()
{
    int kase=1;
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        trie.init();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s);
            trie.insert(s);
        }
        printf("Case %d: %d\n",kase++,trie.ans);
    }
    return 0;
}
