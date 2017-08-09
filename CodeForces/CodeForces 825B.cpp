#include <bits/stdc++.h>
using namespace std;

#define MAXN 12

char g[MAXN][MAXN];

bool win(int i,int j)
{
    if(i>=4 && g[i-1][j]=='X' && g[i-2][j]=='X' && g[i-3][j]=='X' && g[i-4][j]=='X')
        return true;
    if(i>=3 && i<=8 && g[i-1][j]=='X' && g[i-2][j]=='X' && g[i-3][j]=='X' && g[i+1][j]=='X')
        return true;
    if(i>=2 && i<=7 && g[i-1][j]=='X' && g[i-2][j]=='X' && g[i+1][j]=='X' && g[i+2][j]=='X')
        return true;
    if(i>=1 && i<=6 && g[i-1][j]=='X' && g[i+1][j]=='X' && g[i+2][j]=='X' && g[i+3][j]=='X')
        return true;
    if(i<=5 && g[i+1][j]=='X' && g[i+2][j]=='X' && g[i+3][j]=='X' && g[i+4][j]=='X')
        return true;

    if(j>=4 && g[i][j-1]=='X' && g[i][j-2]=='X' && g[i][j-3]=='X' && g[i][j-4]=='X')
        return true;
    if(j>=3 && j<=8 && g[i][j-1]=='X' && g[i][j-2]=='X' && g[i][j-3]=='X' && g[i][j+1]=='X')
        return true;
    if(j>=2 && j<=7 && g[i][j-1]=='X' && g[i][j-2]=='X' && g[i][j+1]=='X' && g[i][j+2]=='X')
        return true;
    if(j>=1 && j<=6 && g[i][j-1]=='X' && g[i][j+1]=='X' && g[i][j+2]=='X' && g[i][j+3]=='X')
        return true;
    if(j<=5 && g[i][j+1]=='X' && g[i][j+2]=='X' && g[i][j+3]=='X' && g[i][j+4]=='X')
        return true;

    if(i>=4 && j>=4 && g[i-1][j-1]=='X' && g[i-2][j-2]=='X' && g[i-3][j-3]=='X' && g[i-4][j-4]=='X')
        return true;
    if(i>=3 && i<=8 && j>=3 && j<=8 && g[i-1][j-1]=='X' && g[i-2][j-2]=='X' && g[i-3][j-3]=='X' && g[i+1][j+1]=='X')
        return true;
    if(i>=2 && i<=7 && j>=2 && j<=7 && g[i-1][j-1]=='X' && g[i-2][j-2]=='X' && g[i+1][j+1]=='X' && g[i+2][j+2]=='X')
        return true;
    if(i>=1 && i<=6 && j>=1 && j<=6 && g[i-1][j-1]=='X' && g[i+1][j+1]=='X' && g[i+2][j+2]=='X' && g[i+3][j+3]=='X')
        return true;
    if(i<=5 && j<=5 && g[i+1][j+1]=='X' && g[i+2][j+2]=='X' && g[i+3][j+3]=='X' && g[i+4][j+4]=='X')
        return true;

    if(i>=4 && j<=5 && g[i-1][j+1]=='X' && g[i-2][j+2]=='X' && g[i-3][j+3]=='X' && g[i-4][j+4]=='X')
        return true;
    if(i>=3 && i<=8 && j>=1 && j<=6 && g[i-1][j+1]=='X' && g[i-2][j+2]=='X' && g[i-3][j+3]=='X' && g[i+1][j-1]=='X')
        return true;
    if(i>=2 && i<=7 && j>=2 && j<=7 && g[i-1][j+1]=='X' && g[i-2][j+2]=='X' && g[i+1][j-1]=='X' && g[i+2][j-2]=='X')
        return true;
    if(i>=1 && i<=6 && j>=3 && j<=8 && g[i-1][j+1]=='X' && g[i+1][j-1]=='X' && g[i+2][j-2]=='X' && g[i+3][j-3]=='X')
        return true;
    if(i<=5 && j>=4 && g[i+1][j-1]=='X' && g[i+2][j-2]=='X' && g[i+3][j-3]=='X' && g[i+4][j-4]=='X')
        return true;
    return false;
}

int main()
{
    for(int i=0; i<10; i++)
        scanf("%s",g[i]);
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(g[i][j]=='.')
            {
                if(win(i,j))
                {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");
    return 0;
}
