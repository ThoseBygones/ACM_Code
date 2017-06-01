#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[15],b[15];

int main()
{
    int n,sum;
    scanf("%d%d",&n,&sum);
    for(int i=0; i<n; i++)
        a[i]=i+1;
    do
    {
        for(int i=0; i<n; i++)
            b[i]=a[i];
        int len=n-1;
        while(len)
        {
            for(int i=0; i<len; i++)
                b[i]=b[i]+b[i+1];
            len--;
            //cout << len << " : " << b[0] << endl;
        }
        //cout << b[0] << endl;
        if(b[0]==sum)
            break;
    }while(next_permutation(a,a+n));
    for(int i=0; i<n; i++)
    {
        if(i==n-1)
            printf("%d\n",a[i]);
        else
            printf("%d ",a[i]);
    }
    return 0;
}
