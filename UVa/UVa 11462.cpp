#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,temp,age[105];
    while(~scanf("%d",&n))
    {
        memset(age,0,sizeof(age));
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&temp);
            age[temp]++;
        }
        bool flag=false;
        for(int i=1; i<=100; i++)
        {
            for(int j=0; j<age[i]; j++)
            {
                if(flag)
                    printf(" ");
                flag=true;
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
