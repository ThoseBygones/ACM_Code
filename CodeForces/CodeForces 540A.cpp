#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

char s[MAXN];
char t[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s %s",s,t);
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=min(abs(s[i]-t[i]),10-abs(s[i]-t[i]));
    printf("%d\n",sum);
    return 0;
}
