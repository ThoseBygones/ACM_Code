#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

char a[15][15];

int main()
{
    int x,y;
    for(int i=0; i<9; i++)
        scanf("%s%s%s",&a[i][0],&a[i][3],&a[i][6]);
    scanf("%d%d",&x,&y);
    while(x>3)
        x-=3;
    while(y>3)
        y-=3;
    bool full=true;
    for(int i=(x-1)*3; i<x*3; i++)
    {
        for(int j=(y-1)*3; j<y*3; j++)
        {
            if(a[i][j]=='.')
            {
                a[i][j]='!';
                full=false;
            }
        }
    }
    if(full)    //本区域已经无空位
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(a[i][j]=='.')
                    a[i][j]='!';
            }
        }
    }
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(j%3==2 && j!=8)
                printf("%c ",a[i][j]);
            else
                printf("%c",a[i][j]);
        }
        puts("");
        if(i%3==2)
            puts("");
    }
    return 0;
}
