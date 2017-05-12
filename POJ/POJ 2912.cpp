//0 -- ƽ��(=)
//1 -- �ӽڵ��ܸ��ڵ�(<)
//2 -- ���ڵ����ӽڵ�(>)
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 505
using namespace std;

int par[MAXN],rela[MAXN];
//int error[MAXN];    //error�����¼ÿ��С���Ƿ������������ʯͷ�������ǲ��ǲ��У�

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
        if((rela[x]+r)%3!=rela[y])  //��ϵ��֮ǰ�ĳ���ì��
            return false;
    }
    else
    {
        par[yy]=xx;
        rela[yy]=(rela[x]+r-rela[y]+rela[xx]+3)%3;  //����֮��Ĺ�ϵ
    }
    return true;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int judgesum=0,judgenum=-1,line=-1; //��ʼ������-1����judge��С��������Ϊ0
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
        for(int k=0; k<n; k++)  //ѭ������ÿ��С�����ж������ǲ���judge
        {
            for(int i=0; i<=n; i++)
            {
                par[i]=i;
                rela[i]=0;
            }
            int j;
            for(j=0; j<m; j++)
            {
                if(game[j].x==k || game[j].y==k)    //�������˲���ľͲ��ٿ���
                    continue;
                if(!unionset(game[j].x,game[j].y,game[j].r))    //�������ì��
                {
                    line=max(line,j);   //�������Ѿ����������
                    break;
                }
            }
            if(j==m)    //��ʼ��û��ì�ܣ���˵�������������С����judge
            {
                judgesum++;
                judgenum=k; //��¼��judge��С���ı��
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
