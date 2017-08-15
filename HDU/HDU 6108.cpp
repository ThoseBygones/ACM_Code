#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MAXN 1005
#define LL long long
#define INF 0x3f3f3f3f
#define MOD 1000000007

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        set <int> s;
        n--;
        for(int i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                s.insert(i);
                s.insert(n/i);
            }
        }
        printf("%d\n",s.size());
    }
    return 0;
}
