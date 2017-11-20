#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 105

int f[MAXN];
string s[MAXN];

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> f[i] >> s[i];
    int smax=1;
    int bmin=k;
    for(int i=1; i<=n; i++)
    {
        if(s[i]=="SAFE")
            smax=max(smax,f[i]);
        else
            bmin=min(bmin,f[i]);
    }
    int l=bmin,r=smax;
    while(l-1>smax)
        l-=1;
    while(r+1<bmin)
        r+=1;
    cout << l << " " << r << endl;
    return 0;
}
