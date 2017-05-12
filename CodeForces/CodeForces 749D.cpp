#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f

vector <int> v[MAXN];   //记录每个人在投标的值
pair <int,int> PII;
set < pair <int,int> > s;   //set中元素的排序是根据pair中的第一个键值排序的

int Max[MAXN];    //记录每个人投标的最大值
int del[MAXN];  //记录每次提问中删除的人

//PII pos1,pos2;

struct Node
{
    int id;
    int val;
} p[MAXN];

int main()
{
    int n,q;
    scanf("%d",&n);
    memset(Max,0,sizeof(Max));
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&p[i].id,&p[i].val);
        v[p[i].id].push_back(p[i].val);
        Max[p[i].id]=max(p[i].val,Max[p[i].id]);
    }
    for(int i=1; i<=n; i++)
    {
        if(Max[i])
            s.insert(make_pair(Max[i],i));  //如果有投标，则在集合中插入它的投标次序和最大投标金额
    }
    scanf("%d",&q);
    for(int i=1; i<=q; i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1; j<=k; j++)
        {
            scanf("%d",&del[j]);
            if(Max[del[j]])
                s.erase(make_pair(Max[del[j]],del[j]));   //如果删除的那个人有投票则抹去他的记录
        }
        if(!s.size())   //如果集合中啥也不剩了，即全部都被抹去了
            printf("0 0\n");
        else if(s.size()==1)    //如果集合中只剩一个人了，那么把他最小的一次投标金额输出
            printf("%d %d\n",s.begin()->second,*v[s.begin()->second].begin());
        else
        {
            auto pos1=s.end();
            auto pos2=s.end();
            pos1--; //最大的
            pos2--,pos2--;    //第二大的
            int val=pos2->first;   //最大的值
            int index=pos1->second;  //最大值对应投标者的编号
            auto it=upper_bound(v[index].begin(),v[index].end(),val);   //二分查找
            printf("%d %d\n",index,*it);
        }
        for(int j=1; j<=k; j++) //该次询问结束，已被删除的补回去
        {
            if(Max[del[j]])
                s.insert(make_pair(Max[del[j]],del[j]));
        }
    }
    return 0;
}
