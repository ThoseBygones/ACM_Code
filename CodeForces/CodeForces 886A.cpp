#include <bits/stdc++.h>
using namespace std;

int a[10];

int main()
{
    int sum=0;
    for(int i=0; i<6; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum&1)
    {
        puts("NO");
        return 0;
    }
    for(int i=0; i<6; i++)
    {
        for(int j=i+1; j<6; j++)
        {
            for(int k=j+1; k<6; k++)
            {
                if(a[i]+a[j]+a[k]==sum/2)
                {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");
    return 0;
}
