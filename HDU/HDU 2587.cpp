#include <iostream>
#define MAXN 1005
#define MOD 20090308
using namespace std;

//移动顺序A->B,B->C,C->A
int ans[MAXN],x[MAXN],y[MAXN],z[MAXN];
//x[n]为将n类盘子按要求顺序移动至间隔柱子需要的步数（例如A->B->C所需步数）
//y[n]为将n类盘子按要求顺序移动至间隔柱子并按照顺序排列需要的步数（例如A->B->C），c[n]相当于在b[n]的基础上再多移动数次以达到最后按顺序排列的要求，起到调整顺序的作用
//z[n]为将n类盘子按要求顺序移动至相邻柱子需要的步数（例如C->A所需的步数）
//x[i]求法：x[i] = x[i-1]+m+z[i-1]+m+x[i-1] = x[i-1]*2+m*2
//y[i]求法：注意！要特判，因为n=2时有更少的步骤就能实现！！！
//          n=2时：y[i] = x[i-1]+1+z[i-1]+1+x[i-1]+1+z[i-1]+1+x[i-2]+1+z[i-2]+1+x[i-2]+1+z[i-2]+1+a[n-2] = x[i-1]*2+z[i-1]*2+x[i-2]*2+z[i-2]*2+8+ans[i-2]
//          y[i] = x[i-1]+m+z[i-1]+m+z[i-1]+m+z[i-1]+m+z[i-1]+m+y[i-1] = x[i-1]+5*m+4*z[i-1]+y[i-1]
//z[i]求法：z[i] = x[i-1]+m+x[i-1] = x[i-1]*2+m
//ans[i]求法：ans[i] = x[i-1]+z[i-1]+y[i-1]+2*m

int n,m;

int main()
{
    ans[0]=x[0]=y[0]=z[0]=0;
    while(cin >> n >> m)
    {
        if(m==1)
        {
            ans[1]=2;
            for(int i=2; i<=n; i++)
            {
                ans[i]=(ans[i-1]*2+ans[i-2]*2+3)%MOD; //递归过程
            }
        }
        else
        {
            ans[1]=2*m; //n=1时直接A->B->C移动，移动后顺序不变
            x[1]=2*m;   //x[n]是将n类盘子按要求顺序移动至间隔柱子需要的步数
            y[1]=2*m;
            z[1]=m; //z[n]是将n类盘子按要求顺序移动至相邻柱子需要的步数
            for(int i=2; i<=n; i++)
            {
                z[i]=(x[i-1]*2+m)%MOD;
                x[i]=(x[i-1]*2+m*2+z[i-1])%MOD;
                if(m==2)
                    y[i]=(x[i-1]*2+z[i-1]*2+x[i-2]*2+z[i-2]*2+8+ans[i-2])%MOD;
                else
                    y[i]=(x[i-1]+5*m+4*z[i-1]+y[i-1])%MOD;
                ans[i]=(x[i-1]+z[i-1]+y[i-1]+2*m)%MOD;
            }
        }
        cout << ans[n] << endl;
    }
    return 0;
}
