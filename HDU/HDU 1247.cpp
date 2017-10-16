#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Trie
{
public:
#define CHAR_NUM 26 //10--只有数字，26--只有大写/小写字母，52--大小写字母都有，62--数字+大小写字母
#define MAXNODE 500005

    struct node
    {
        int next[CHAR_NUM];
        int val;
        bool ed;    //是否已经结束
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
            //int pos = s[i]-'0';
            if(nd[temp].next[pos]==-1) nd[temp].next[pos] = newnode();
            temp = nd[temp].next[pos];
            nd[temp].val++;
        }
        nd[temp].ed=true;
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
        return nd[temp].ed;
    }
} trie;

char s[50005][55];

int main()
{
    int index = 1;
    trie.init();
    while(~scanf("%s",s[++index]))
    {
        trie.insert(s[index]);
    }
    char a[55],b[55];
    for(int i=1; i<=index; i++)
    {
        int len=strlen(s[i]);
        for(int j=0; j<len; j++)
        {
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            strncpy(a,s[i],j);
            strncpy(b,s[i]+j,len-j);
            //printf("%s\n",a);
            //printf("%s\n",b);
            if(trie.find(a) && trie.find(b))
            {
                printf("%s\n",s[i]);
                break;
            }
        }
    }
    return 0;
}
