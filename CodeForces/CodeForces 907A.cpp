#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int x,y,z,m;
    scanf("%d%d%d%d",&x,&y,&z,&m);
    if(m>=y || m>2*z || 2*m<z)    //Masha体型不能等于熊妈；Masha体型不能大于2倍的熊儿子；Masha必须喜欢最小的这辆车
        puts("-1");
    else
        printf("%d\n%d\n%d\n",2*x,2*y,max(z,m));
    return 0;
}
