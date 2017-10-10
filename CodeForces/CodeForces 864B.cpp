#include <bits/stdc++.h>
using namespace std;

#define MAXN 205

char str[MAXN];
set <int> s;

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            ans=max(ans,(int)s.size());
            s.clear();
        }
        else
            s.insert(str[i]);
    }
    ans=max(ans,(int)s.size());
    printf("%d\n",ans);
    return 0;
}
