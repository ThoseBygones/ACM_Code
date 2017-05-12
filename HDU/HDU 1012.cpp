#include<iostream>
#include<iomanip>
using namespace std;

double a[10];

int main()
{
    double sum;
    a[0]=1.0;
    for(int i=1; i<=9; i++)
    {
        sum=1;
        for(int j=i; j>0; j--)
            sum*=j;
        a[i]=sum;
    }
    //for(int i=0; i<=9; i++)
        //cout << a[i] << endl;
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    cout << "0 1" << endl;
    cout << "1 2" << endl;
    cout << "2 2.5" << endl;
    for(int i=1; i<=9; i++)
        a[i]=1.0/a[i];
    sum=0.0;
    for(int i=0; i<=9; i++)
    {
        sum+=a[i];
        if(i>=3)
            cout << i << " " << fixed << setprecision(9) << sum << endl;
    }
    return 0;
}
