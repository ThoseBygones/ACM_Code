#include <iostream>
#define LL long long
using namespace std;

LL num[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};

int main()
{
    int n;
    LL sum=0;
    cin >> n;
    for(int i=1; i<=11; i++)
    {
        if(n<num[i])
        {
            sum+=(n-num[i-1]+1)*(i-1);
            for(int j=i-1; j>=2; j--)
                sum+=(num[j]-num[j-1])*(j-1);
            break;
        }
    }
    cout << sum << endl;
}
