#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,sum,i;
    while((scanf("%d",&n))!=EOF)
    {
        sum=0;
        for(i=0; i<n; i++)
        {
            sum=sum+(i+1)*i/2+1;
        }
        sum=sum+1;
        cout<<sum<<endl;
    }
    return 0;
}
