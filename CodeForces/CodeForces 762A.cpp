#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

vector <LL> a,b;    //a存小于sqrt(n)的因子，b存大于sqrt(n)的因子

int main()
{
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    for(LL i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            a.push_back(i);
            if(i*i!=n)
                b.push_back(n/i);
        }
    }
    LL len=(LL)a.size()+(LL)b.size();
    //cout << a.size() << b.size() << endl;
    if(len<k)
    {
        puts("-1");
        return 0;
    }
    else
    {
        if(k>a.size())
            printf("%I64d\n",b[b.size()-(k-a.size()-1)-1]);
        else
            printf("%I64d\n",a[k-1]);
    }
    return 0;
}
