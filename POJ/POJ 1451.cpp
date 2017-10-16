#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

const char mp[30] = "22233344455566677778889999";

char t[1005][MAXN];
int p[1005][MAXN];
char q[MAXN];
int prob;

class Trie
{
public:
#define CHAR_NUM 10 //10--只有数字，26--只有大写/小写字母，52--大小写字母都有，62--数字+大小写字母
#define MAXNODE 500005

    struct node
    {
        int next[CHAR_NUM];
        int val;
        char s[105];
        void init()
        {
            memset(next,0,sizeof(next));
            memset(s,0,sizeof(s));
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

    void insert(char *s,int id)
    {
        int temp = root;
        for(int i = 0; s[i]; i++)
        {
            int pos = mp[s[i] - 'a'] - '0';
            if(nd[temp].next[pos]==0) nd[temp].next[pos] = newnode();
            temp = nd[temp].next[pos];
            if(p[id][i]>nd[temp].val)
            {
                nd[temp].val = p[id][i];
                for(int j=0; j<=i; j++)
                    nd[temp].s[j]=t[id][j];
            }
        }
    }

    void find(char *s)
    {
        int temp = root;
        bool flag = false;
        for(int i = 0; s[i]; i++)
        {
            int pos = s[i] - '0';
            if(pos==1)
                break;
            temp = nd[temp].next[pos];
            if(temp==0 || nd[temp].val==0 || flag)
            {
                puts("MANUALLY");
                flag = true;
            }
            else
                printf("%s\n",nd[temp].s);
        }
    }
} trie;

int main()
{
    int kase=1;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d",&n);
        memset(p,0,sizeof(p));
        trie.init();
        for(int i=0; i<n; i++)
        {
            int prob;
            scanf("%s%d",t[i],&prob);
            int len=strlen(t[i]);
            for(int j=0; j<len; j++)
                p[i][j]=prob;
        }
        for(int i=1; i<n; i++)
        {
            for(int j=0; t[i][j]; j++)
            {
                if(t[i][j]==t[i-1][j])
                {
                    p[i][j]+=p[i-1][j];
                    p[i-1][j]=0;
                }
                else
                    break;
            }
        }
        for(int i=0; i<n; i++)  //不能在前面，不然如果总权值相同不一定输出的是字典序较小的关键词
            trie.insert(t[i],i);
        scanf("%d",&m);
        printf("Scenario #%d:\n",kase++);
        while(m--)
        {
            scanf("%s",q);
            trie.find(q);
            puts("");
        }
        puts("");
    }
    return 0;
}
