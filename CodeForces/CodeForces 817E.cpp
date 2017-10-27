#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//字典树（Trie）模板

#define DIGIT_NUM 32    //数位数量，int为32，long long为64
#define INF 0x3fffffff

class Trie
{
public:
#define CHAR_NUM 2  //2--01（异或）字典树，10--只有数字，26--只有大写/小写字母，52--大小写字母都有，62--数字+大小写字母
#define MAXNODE 5000005

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

    void insert(int val)
    {
        int temp = root;
        for(int i = DIGIT_NUM-1; i>=0; i--)
        {
            int pos = (val & (1 << i)) ? 1 : 0;
            if(nd[temp].next[pos]==-1) nd[temp].next[pos] = newnode();
            temp = nd[temp].next[pos];
            nd[temp].val++;
        }
    }

    void del(int val)
    {
        int temp = root;
        for(int i = DIGIT_NUM-1; i>=0; i--)
        {
            int pos = (val & (1 << i)) ? 1 : 0;
            temp = nd[temp].next[pos];
            nd[temp].val--;
        }
    }

    /*以下为01（异或）字典树需要增加的操作（用query函数替代find函数）*/
    /*求与给定数异或的最大值，不要把0插入字典树*/
    /*求与给定数异或的最大值，不要把0插入字典树*/
    /*求一段区间的最大（小）异或值和，类似前缀和的形式预处理：sum[i] ^= sum[i-1]
    一段区间[l,r]的异或值就等于：sum[r]^sum[l-1]
    然后问题就转化成了求区间两端的数
    注意要先把0插入字典树
    */

    //查询最大（小）值函数
    //如果要求最大值，就尽量往反方向走（如果是0，就往1走，如果是1，就往0走）
    //如果要求最小值，就尽量往同方向走（如果是0，就往0走，如果是1，就往1走）
    int query(int p, int l)
    {
        int temp = root;
        int res = 0;
        for(int i = DIGIT_NUM-1; i>=0; i--) //从高位开始往低位遍历
        {
            int tp = (p & (1 << i)) ? 1 : 0;
            int tl = (l & (1 << i)) ? 1 : 0;
            //根据异或运算：
            //如果在第i位上指挥官的领导力为0：
            //  1.如果该指挥官的个性值为0，那么个性值为1的战士就不会敬重他。接着再比较个性值为0的战士里剩余的位；
            //  2.如果该指挥官的个性值为1，那么个性值为0的战士就不会敬重他。接着再比较个性值为1的战士里剩余的位；
            //如果在第i位上指挥官的领导力为1：
            //  1.如果该指挥官的个性值为0，那么个性值为0的战士就不会敬重他。接着再比较个性值为1的战士里剩余的位；
            //  2.如果该指挥官的个性值为1，那么个性值为1的战士就不会敬重他。接着再比较个性值为0的战士里剩余的位；
            if(tl)
            {
                int pos = nd[temp].next[tp];
                res += nd[pos].val;
            }
            temp = nd[temp].next[tp ^ tl];
            if(temp==-1)
                break;
        }
        return res;
    }
} trie;

int main()
{
    trie.init();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int op,p;
        scanf("%d",&op);
        if(op==1)
        {
            int p;
            scanf("%d",&p);
            trie.insert(p);
        }
        else if(op==2)
        {
            int p;
            scanf("%d",&p);
            trie.del(p);
        }
        else
        {
            int p,l;
            scanf("%d%d",&p,&l);
            printf("%d\n",trie.query(p,l));
        }
    }
    return 0;
}
