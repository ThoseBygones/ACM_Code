#include <cstdio>
#define MAXN 1005
using namespace std;

struct Node
{
    int num;
    int par;
    int indegree;//数据、根、入度
};

Node node[MAXN];

void init()
{
    for(int i = 0; i < MAXN; i++)
    {
        node[i].indegree = 0;//入度初始化为0
        node[i].par= i;//根记录为自身
        node[i].num=0;//标记数字是否被使用过，0:没有被使用过，1:使用过了
    }
}

int findset(int a)
{
    if(node[a].par!=a)
        return node[a].par = findset(node[a].par);
    return node[a].par;
}

void mergeset(int a,int b)
{
    a = findset(a);
    b = findset(b);
    if(a==b)//同一个根，说明是在同一个树下
        return;
    node[b].par=a;//把b的根赋为a的根，此时a已经是根，num==par
}

int main()
{
    int n,m;
    int kase = 1;
    bool flag=true;//true：是个树，false:不是树
    init();
    while(scanf("%d%d",&n,&m)!=EOF&&n>=0&&m>=0)
    {
        if(!flag&&n!=0&&n!=0)continue;//已经确定不是树了，就继续循环
        if(n==0&&m==0)
        {
            int root_num=0;
            for(int j = 1; j < MAXN; j++)
            {
                //判断是否为森林，如果，root_num用来记录根的数目
                if(node[j].num && findset(j)==j)
                    root_num++;
                if(node[j].indegree>1)//如果出现某个节点的入度超过1，不是树
                {
                    flag = false;
                    break;
                }
            }
            if(root_num>1)//连通分支大于1，是森林不是树
                flag=false;
            if(flag)
                printf("Case %d is a tree.\n",kase++);
            else printf("Case %d is not a tree.\n",kase++);
            flag = true;
            init();
            continue;
        }
        if(m!=n&&findset(n)==findset(m))
            flag = false;
        else
        {
            //将m,n，记录为节点
            node[m].num = 1;
            node[n].num = 1;
            node[m].indegree++;//入度增加一
            mergeset(n,m);
        }
    }
    return 0;
}
