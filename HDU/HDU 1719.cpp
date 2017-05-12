#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0)
        {
            cout << "NO!" << endl;
            continue;
        }
        n++;
        while(n%2==0)
            n/=2;
        while(n%3==0)
            n/=3;
        if(n==1)
            cout << "YES!" <<endl;
        else
            cout << "NO!" << endl;
    }
    return 0;
}
