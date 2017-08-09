#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define LL long long

set <int> s;

char str[MAXN];
int st[30];
int ed[30];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    for(int i=1; i<=n; i++)
    {
        if(!st[str[i]-'A'])
            st[str[i]-'A']=i;
        ed[str[i]-'A']=i;
    }
    int Max=0;
    for(int i=1; i<=n; i++)
    {
        if(!s.count(str[i]-'A'))
            s.insert(str[i]-'A');
        Max=max(Max,(int)s.size());
        //cout << Max << endl;
        for(int j=0; j<26; j++)
        {
            if(i==ed[j])
            {
                s.erase(j);
                break;
            }
        }
    }
    if(Max>k)
        puts("YES");
    else
        puts("NO");
    //printf("%d\n",Max);
    return 0;
}
