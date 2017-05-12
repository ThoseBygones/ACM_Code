#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int N,i,sum,a[105]= {0};
    while(~scanf("%d",&N)&&N)
    {
        sum=0;
        for(i=1; i<N+1; i++)
            cin>>a[i];
        for(i=1; i<N+1; i++)
        {
            if(a[i-1]<=a[i])
                sum=sum+(a[i]-a[i-1])*6+5;
            else
                sum=sum+(a[i-1]-a[i])*4+5;
        }
        cout<<sum<<endl;
    }
    return 0;
}
