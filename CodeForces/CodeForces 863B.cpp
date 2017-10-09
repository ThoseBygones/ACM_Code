#include <bits/stdc++.h>
using namespace std;

#define MAXN 110
#define INF 0x3fffffff
#define PB push_back

int a[MAXN];
vector <int> v;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=2*n; i++)
        scanf("%d",&a[i]);
    int ans=INF;
    for(int i=1; i<=n*2; i++)
    {
        for(int j=i+1; j<=n*2; j++)
        {
            for(int k=1; k<=n*2; k++)
            {
                if(k!=i && k!=j)
                    v.PB(a[k]);
            }
            sort(v.begin(),v.end());
            int sum=0;
            for(int k=0; k<v.size(); k+=2)
                sum+=v[k+1]-v[k];
            ans=min(ans,sum);
            v.clear();
        }
    }
    printf("%d\n",ans);
    return 0;
}
