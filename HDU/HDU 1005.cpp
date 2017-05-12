#include<iostream>
using namespace std;

int a,b,n,arr[55];

int main()
{
    int ls=0,le=0;
    arr[1]=arr[2]=1;
    while(cin >> a >> b >> n,a,b,n)
    {
        bool flag=false;
        for(int i=3; i<=n && !flag; i++)
        {
            arr[i]=(a*arr[i-1]+b*arr[i-2])%7;
            for(int j=2; j<=i-1; j++)
            {
                if(arr[i]==arr[j] && arr[i-1]==arr[j-1])
                {
                    ls=j;
                    le=i;
                    flag=true;
                    break;
                }
            }
        }
        if(flag)
            cout << arr[ls+(n-le)%(le-ls)] << endl;
        else
            cout << arr[n] << endl;
    }
    return 0;
}

///周期性+打表
/*
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int a,b,n,i;
int arry[60];
int main()
{
    while(scanf("%d%d%d",&a,&b,&n),(a||b||n))
    {
        arry[1] = arry[2] = 1;
        for(i = 3;i < 60;i++)
            arry[i] = (a*arry[i-1] + b*arry[i-2])%7;
        n%=49;
        printf("%d\n",arry[n]);
    }
    return 0;
}
*/
