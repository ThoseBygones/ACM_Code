#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

char num[15];
int k;

int main()
{
    scanf("%s",num);
    scanf("%d",&k);
    int n=strlen(num);
    int cnt=0;
    int zero=0;
    bool flag=false;
    for(int i=n-1; i>=0; i--)
    {
        if(zero==k)
        {
            flag=true;
            break;
        }
        if(num[i]!='0')
            cnt++;
        else
            zero++;
    }
    if(flag)
        printf("%d\n",cnt);
    else
        printf("%d\n",n-1);
}
