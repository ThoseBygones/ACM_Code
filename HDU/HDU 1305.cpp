#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Trie
{
public:
#define CHAR_NUM 2  //10--只有数字，26--只有大写/小写字母，52--大小写字母都有，62--数字+大小写字母
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
            //int pos = s[i]-'a';
            int pos = s[i]-'0';
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
            //int pos = s[i]-'a';
            int pos = s[i]-'0';
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

char s[15][15];

int main()
{
    int kase=1;
    int index=0;
    trie.init();
    while(~scanf("%s",s[++index]))
    {
        if(s[index][0]=='9')
        {
            bool flag=true;
            for(int i=1; i<index; i++)
            {
                if(trie.find(s[i])!=1)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                printf("Set %d is immediately decodable\n",kase++);
            else
                printf("Set %d is not immediately decodable\n",kase++);
            index=0;
            trie.init();
            continue;
        }
        trie.insert(s[index]);
    }
    return 0;
}
