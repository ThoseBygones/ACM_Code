#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Trie
{
public:
#define CHAR_NUM 10 //大小写字母都考虑则是52，再加上数字是62
#define MAXNODE 500005

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

    void insert(char *s)
    {
        int temp = root;
        for(int i = 0; s[i]; i++)
        {
            int pos = s[i]-'0'; //数字
            if(nd[temp].next[pos]==-1) nd[temp].next[pos] = newnode();
            temp = nd[temp].next[pos];
            nd[temp].val++;
        }
    }

    int find(char *s)
    {
        int temp = root;
        for(int i = 0; s[i]; i++)
        {
            int pos = s[i]-'0'; //数字
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

char num[10005][15];

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        trie.init();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",num[i]);
            trie.insert(num[i]);
        }
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            //printf("%d\n",trie.find(num[i]));
            if(trie.find(num[i])!=1)
            {
                flag=false;
                break;
            }
        }
        printf("Case %d: ",kase++);
        puts(flag?"YES":"NO");
    }
    return 0;
}
