#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int gcd(int x,int y)
{
    if(x%y==0)
        return y;
    else
        return gcd(y,x%y);
}

int main()
{
    int step,mod;
    while(cin >> step >> mod)
    {
        int a=max(step,mod);
        int b=min(step,mod);
        cout << fixed << setw(10) << step << fixed << setw(10) << mod << "    ";
        if(gcd(a,b)==1)
            cout << "Good Choice" << endl << endl;
        else
            cout << "Bad Choice" << endl << endl;
    }
    return 0;
}
