#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

vector <int> f;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=2; i<=n; i++)
    {
        while(n%i==0)
        {
            f.push_back(i);
            n/=i;
        }
    }
    if(k>f.size())
        puts("-1");
    else
    {
        int sum=1;
        for(int i=0; i<k-1; i++)
            printf("%d ",f[i]);
        for(int i=k-1; i<f.size(); i++)
            sum*=f[i];
        printf("%d\n",sum);
    }
    return 0;
}
