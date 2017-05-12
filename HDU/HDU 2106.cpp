#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n,x,y;
    while(~scanf("%d",&n))
    {
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            int sum=0;
            int cnt=0;
            scanf("%d(%d)",&x,&y);
            while(x)
            {
                sum+=(x%10)*pow(y,cnt);
                x/=10;
                cnt++;
            }
            ans+=sum;
            //printf("%d\n",ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
