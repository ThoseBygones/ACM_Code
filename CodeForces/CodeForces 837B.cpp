#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

char s[MAXN][MAXN];

bool check(int xl,int xr,int xt,int xb,char col)
{
    for(int i=xt; i<=xb; i++)
    {
        for(int j=xl; j<=xr; j++)
        {
            if(s[i][j]!=col)
                return false;
        }
    }
    return true;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%s",s[i]);
    }
    if(n%3 && m%3)
    {
        puts("NO");
        return 0;
    }
    int rl=m-1,rr=0,rt=n-1,rb=0;
    int gl=m-1,gr=0,gt=n-1,gb=0;
    int bl=m-1,br=0,bt=n-1,bb=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='R')
            {
                rl=min(j,rl);
                rr=max(j,rr);
                rt=min(i,rt);
                rb=max(i,rb);
            }
            if(s[i][j]=='G')
            {
                gl=min(j,gl);
                gr=max(j,gr);
                gt=min(i,gt);
                gb=max(i,gb);
            }
            if(s[i][j]=='B')
            {
                bl=min(j,bl);
                br=max(j,br);
                bt=min(i,bt);
                bb=max(i,bb);
            }
        }
    }
    //printf("%d %d %d %d\n",rl,rr,rt,rb);
    //printf("%d %d %d %d\n",gl,gr,gt,gb);
    //printf("%d %d %d %d\n",bl,br,bt,bb);
    if(check(rl,rr,rt,rb,'R') && check(gl,gr,gt,gb,'G') && check(bl,br,bt,bb,'B'))
    {
        if(rt==gt && gt==bt && rb==gb && gb==bb && rr-rl==gr-gl && br-bl==gr-gl)
        {
            puts("YES");
            return 0;
        }
        if(rl==gl && gl==bl && rr==gr && gr==br && rb-rt==gb-gt && bb-bt==gb-gt)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
