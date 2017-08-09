#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

char s[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    bool flag=true;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='1')
        {
            cnt++;
            flag=true;
        }
        else
        {
            if(flag)
            {
                flag=false;
                printf("%d",cnt);
                cnt=0;
            }
            else
                printf("0");
        }
    }
    printf("%d\n",cnt);
    return 0;
}
