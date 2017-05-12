#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

char str[105];
int ans[5];

int main()
{
    scanf("%s",str+1);
    memset(ans,0,sizeof(ans));
    int len=strlen(str+1);
    int r,b,y,g;
    for(int i=1; i<=len; i++)
    {
        if(str[i]=='R')
            r=i%4;
        else if(str[i]=='B')
            b=i%4;
        else if(str[i]=='Y')
            y=i%4;
        else if(str[i]=='G')
            g=i%4;
        else if(str[i]=='!')
            ans[i%4]++;
    }
    printf("%d %d %d %d\n",ans[r],ans[b],ans[y],ans[g]);
    return 0;
}
