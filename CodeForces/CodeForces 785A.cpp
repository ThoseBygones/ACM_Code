#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

map <string,int> mp;

int main()
{
    mp["Tetrahedron"]=4;
    mp["Cube"]=6;
    mp["Octahedron"]=8;
    mp["Dodecahedron"]=12;
    mp["Icosahedron"]=20;
    int n;
    while(~scanf("%d",&n))
    {
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            char str[20];
            scanf("%s",str);
            ans+=mp[str];
        }
        printf("%d\n",ans);
    }
    return 0;
}
