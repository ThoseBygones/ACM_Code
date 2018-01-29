#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

char s[MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    while(m--)
    {
        int l,r;
        char c1,c2;
        scanf("%d %d %c %c",&l,&r,&c1,&c2);
        for(int i=l; i<=r; i++)
        {
            if(s[i]==c1)
                s[i]=c2;
        }
    }
    printf("%s\n",s+1);
    return 0;
}
