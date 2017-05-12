//0 -- 平局(=)
//1 -- 子节点打败父节点(<)
//2 -- 父节点打败子节点(>)
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 505
using namespace std;

int par[MAXN],rela[MAXN];
//int error[MAXN];    //error数组记录每个小孩是否能随意出剪刀石头布（即是不是裁判）

struct Relation
{
    int x;
    int y;
    int r;
} game[2005];

int findset(int r)
{
    if(par[r]!=r)
    {
        int temp=par[r];
        par[r]=findset(par[r]);
        rela[r]=(rela[r]+rela[temp])%3;
    }
    return par[r];
}

bool unionset(int x,int y,int r)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx==yy)
    {
        if((rela[x]+r)%3!=rela[y])  //关系与之前的出现矛盾
            return false;
    }
    else
    {
        par[yy]=xx;
        rela[yy]=(rela[x]+r-rela[y]+rela[xx]+3)%3;  //种类之间的关系
    }
    return true;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int judgesum=0,judgenum=-1,line=-1; //初始化行数-1，是judge的小孩的数量为0
        for(int i=0; i<m; i++)
        {
            char sign;
            scanf("%d%c%d",&game[i].x,&sign,&game[i].y);
            if(sign=='=')
                game[i].r=0;
            else if(sign=='<')
                game[i].r=1;
            else if(sign=='>')
                game[i].r=2;
        }
        for(int k=0; k<n; k++)  //循环遍历每个小孩，判断他们是不是judge
        {
            for(int i=0; i<=n; i++)
            {
                par[i]=i;
                rela[i]=0;
            }
            int j;
            for(j=0; j<m; j++)
            {
                if(game[j].x==k || game[j].y==k)    //有它本人参与的就不再考虑
                    continue;
                if(!unionset(game[j].x,game[j].y,game[j].r))    //如果出现矛盾
                {
                    line=max(line,j);   //保留下已经处理的行数
                    break;
                }
            }
            if(j==m)    //若始终没有矛盾，则说明遍历到的这个小孩是judge
            {
                judgesum++;
                judgenum=k; //记录是judge的小孩的编号
            }
        }
        if(judgesum==0)
            printf("Impossible\n");
        else if(judgesum>1)
            printf("Can not determine\n");
        else
            printf("Player %d can be determined to be the judge after %d lines\n",judgenum,line+1);
    }
    return 0;
}
