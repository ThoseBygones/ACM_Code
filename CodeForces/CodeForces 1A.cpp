#include<iostream>
using namespace std;

int main()
{
    long long int n,m,a,num1,num2,sum;
    cin >> n >> m >> a;
    if(n%a==0)
        num1=n/a;
    else
        num1=n/a+1;
    if(m%a==0)
        num2=m/a;
    else
        num2=m/a+1;
    sum=num1*num2;
    cout << sum << endl;
    return 0;
}
