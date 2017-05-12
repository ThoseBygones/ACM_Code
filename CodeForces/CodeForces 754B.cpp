#include <bits/stdc++.h>
#define LL long long
using namespace std;

char g[5][5];

int main()
{
    for(int i=0; i<4; i++)
        scanf("%s",g[i]);
    bool flag=false;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(g[i][j]=='.')
            {
                if(i+2<4 && g[i+1][j]=='x' && g[i+2][j]=='x')
                    flag=true;
                if(i-1>=0 && i+1<4 && g[i-1][j]=='x' && g[i+1][j]=='x')
                    flag=true;
                if(i-2>=0 && g[i-1][j]=='x' && g[i-2][j]=='x')
                    flag=true;

                if(j+2<4 && g[i][j+1]=='x' && g[i][j+2]=='x')
                    flag=true;
                if(j-1>=0 && j+1<4 && g[i][j-1]=='x' && g[i][j+1]=='x')
                    flag=true;
                if(j-2>=0 && g[i][j-1]=='x' && g[i][j-2]=='x')
                    flag=true;

                if(i+2<4 && j+2<4 && g[i+1][j+1]=='x' && g[i+2][j+2]=='x')
                    flag=true;
                if(i-1>=0 && i+1<4 && j-1>=0 && j+1<4 && g[i-1][j-1]=='x' && g[i+1][j+1]=='x')
                    flag=true;
                if(i-2>=0 && j-2>=0 && g[i-1][j-1]=='x' && g[i-2][j-2]=='x')
                    flag=true;

                if(i-2>=0 && j+2<4 && g[i-1][j+1]=='x' && g[i-2][j+2]=='x')
                    flag=true;
                if(i-1>=0 && i+1<4 && j-1>=0 && j+1<4 && g[i-1][j+1]=='x' && g[i+1][j-1]=='x')
                    flag=true;
                if(i+2<4 && j-2>=0 && g[i+1][j-1]=='x' && g[i+2][j-2]=='x')
                    flag=true;
            }
        }
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
