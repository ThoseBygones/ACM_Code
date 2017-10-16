#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Trie
{
public:
#define CHAR_NUM 26
#define MAXNODE 500005

    struct node
    {
        int next[CHAR_NUM];
        int val;    //以当前字符串为前缀的单词的数量
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
            int pos = s[i]-'a';
            if(nd[temp].next[pos]==-1) nd[temp].next[pos] = newnode();
            temp = nd[temp].next[pos];
            nd[temp].val++;
        }
    }

    void find(char *s)
    {
        int temp = root;
        for(int i = 0; s[i]; i++)
        {
            int pos = s[i]-'a';
            if(nd[temp].next[pos]==-1)
            {
                return ;
            }
            else
            {
                temp = nd[temp].next[pos];
                printf("%c",s[i]);
            }
            if(nd[temp].val==1) //该结点对应唯一的单词
                return ;
        }
    }
} trie;

char s[1005][25];

int main()
{
    int index=0;
    trie.init();
    while(~scanf("%s",s[++index]))
    {
        trie.insert(s[index]);
    }
    for(int i=1; i<=index; i++)
    {
        printf("%s ",s[i]);
        trie.find(s[i]);
        puts("");
    }
    return 0;
}
