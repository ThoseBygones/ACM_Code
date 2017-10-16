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
        int flag;
        void init()
        {
            memset(next,-1,sizeof(next));
            val = 0;
            flag = 0;
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

    void insert(char *s,int id)
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
        nd[temp].flag = id;
    }

    int find(char *s)
    {
        int temp = root;
        for(int i = 0; s[i]; i++)
        {
            int pos = s[i]-'a';
            //int pos = s[i]-'0';
            //cout << nd[temp].flag << endl;
            if(nd[temp].next[pos]==-1)
            {
                return 0;
            }
            else
                temp = nd[temp].next[pos];
        }
        return nd[temp].flag;
    }
} trie;

char a[500005][15],b[500005][15];
char s[3005],t[3005];

int main()
{
    int index=1;
    trie.init();
    while(~scanf("%s",a[index]))
    {
        if(strcmp(a[index],"START")==0)
            continue;
        if(strcmp(a[index],"END")==0)
            break;
        scanf("%s",b[index]);
        trie.insert(b[index],index);
        index++;
    }
    getchar();
    index--;
    //cout << index << endl;
    while(gets(s))
    {
        if(strcmp(s,"START")==0)
            continue;
        if(strcmp(s,"END")==0)
            break;
        int i=0;
        while(s[i])
        {
            if(s[i]>='a' && s[i]<='z')
            {
                int j=0;
                memset(t,0,sizeof(t));
                while(s[i] && s[i]>='a' && s[i]<='z')
                    t[j++]=s[i++];
                //t[j]='\0';
                //cout << "#" << t << endl;
                int idx=trie.find(t);
                //cout << idx << endl;
                if(idx)
                    printf("%s",a[idx]);
                else
                    printf("%s",t);
            }
            else
                printf("%c",s[i++]);
        }
        puts("");
    }
    return 0;
}

/*
START
dog aa
END
START
a aa
END
*/
