#include<stdio.h>
#include<string.h>
#include<math.h>

char map[110][110];
int m,n;
int XY[8][2]= {{-1,1},{0,1},{1,1},{-1,0},{1,0},{-1,-1},{0,-1},{1,-1}};

void dfs(int x,int y)
{
    int Ix,Iy,i;
    for(i=0; i<8; i++)
    {
        Ix=x+XY[i][0];
        Iy=y+XY[i][1];
        if(map[Ix][Iy]=='@')
        {
            map[Ix][Iy]='*';
            dfs(Ix,Iy);
        }
    }
}

int main()
{
    while(1)
    {
        int i,j;
        scanf("%d %d",&m,&n);
        if(m==0&&n==0)
            break;
        for(i=0; i<m; i++)
            scanf("%s",map[i]);
        int count=0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(map[i][j]=='@')
                {
                    dfs(i,j);
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
