#include<stdio.h>
#include<string.h>

int map[110][110];
int len[110][110];
int R,C;
int axisX[4]={1,0,-1,0};
int axisY[4]={0,1,0,-1};

int inmap(int x,int y)
{
    if(x<0||y<0||x>=R||y>=C)
        return 0;
    return 1;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int dfs(int x,int y)
{
    int Ix,Iy,i;
    if(len[x][y]==0)
    {
        for(i=0;i<4;i++)
        {
            Ix=x+axisX[i];
            Iy=y+axisY[i];
            if(inmap(Ix,Iy)&&map[Ix][Iy]<map[x][y])
            {
                int temp=dfs(Ix,Iy);
                if(len[x][y]<=temp)
                    len[x][y]=temp;
            }
        }

    }
    return len[x][y]+1;
}

int main()
{
    while(scanf("%d %d",&R,&C)!=EOF)
    {
        int i,j,maxlength;
        memset(len,0,sizeof(len));
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        maxlength=-1;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                maxlength=max(maxlength,dfs(i,j));
            }
        }
        printf("%d\n",maxlength);
    }
    return 0;
}
