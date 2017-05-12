#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

int main()
{
    int n,m;
    string str;
    scanf("%d",&n);
    bool flag=true;
    int x=0;
    while(n--)
    {
        cin >> m >> str;
        if(!flag)
            continue;
        if((x==0 && str!="South") || (x==20000 && str!="North"))
        {
            flag=false;
            continue;
        }
        if(str=="East" || str=="West")
            continue;
        if(str=="South")
        {
            if(x+m>20000)
            {
                flag=false;
                continue;
            }
            else
                x+=m;
        }
        if(str=="North")
        {
            if(x-m<0)
            {
                flag=false;
                continue;
            }
            else
                x-=m;
        }
    }
    if(x==0 && flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
