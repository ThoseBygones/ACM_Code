#include<iostream>
#include<iomanip>
using namespace std;

double a,b,c,m,n;

double f(int x)
{
    return a * x * x * x / 3 - (2 * a * b + m) * x * x / 2 + (a * b * b + c - n) * x;
}

int main()
{
    int T;
    double x1,y1,x2,y2,x3,y3;
    cin >> T;
    while(T--)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        m = (y3 - y2) / (x3 - x2);
        n = y2 - m * x2;
        a = (y2 - y1) / ((x2 - x1) * (x2 - x1));
        b = x1;
        c = y1;
        double S = f(x3) - f(x2);
        //cout << x1 << " " << y1 << endl << x2 << " " << y2 << endl << x3 << " " << y3 << endl;
        //cout << m << endl << n << endl << a << endl <<  b << endl;
        cout << fixed << setprecision(2) << S << endl;
    }
    return 0;
}
