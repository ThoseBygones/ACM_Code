#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1005

set <int> s;

int side[5];

int main()
{
    for(int i=1; i<=3; i++)
    {
        scanf("%d",&side[i]);
        s.insert(side[i]);
    }
    bool flag=true;
    for(int i=1; i<=3; i++)
    {
        int temp;
        scanf("%d",&temp);
        if(!s.count(temp))
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        sort(side+1,side+4);
        if(side[1]*side[1]+side[2]*side[2]==side[3]*side[3])
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
