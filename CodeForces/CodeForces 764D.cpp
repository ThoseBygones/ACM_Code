//对于任意两个相邻的矩形，其必有(x1与x2)或(y1与y2)的奇偶性不一致（因为所有矩形边长均为奇数）
//由于我们有4种染色方案（设为1 2 3 4），因此我们可以构造其染色情况为[(x%2+2*(y%2))+4]%4+1（其中x和y表示该矩形左下角坐标），即可保证相邻的矩形中没有同色的情况（因为该染色情况下同色当且仅当x与y的奇偶性一致）。
#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005

struct Rectangle
{
    int a;
    int b;
    int c;
    int d;
} rec[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d%d%d",&rec[i].a,&rec[i].b,&rec[i].c,&rec[i].d);
    puts("YES");    //这里永远都是YES，因为1976年，美国俩逗逼数学家Appel和Haken宣称证明了四色猜想，虽然大部分数学家对这个证明并不满意...
    for(int i=1; i<=n; i++) //先判定俩矩形是否有公共边。有公共边的条件是俩矩形对应的顶点（要么都为左下角的顶点，要么都为右上角的顶点）x或y中有一个奇偶性相同
    {
        if(rec[i].a%2 && rec[i].b%2)
            puts("1");
        else if(rec[i].a%2 && !(rec[i].b%2))
            puts("2");
        else if(!(rec[i].a%2) && rec[i].b%2)
            puts("3");
        else
            puts("4");
    }
    return 0;
}
