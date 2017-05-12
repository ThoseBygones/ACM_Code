#include <iostream>
#include <algorithm>
using namespace std;

struct Laptop
{
    int a;
    int b;
    bool operator <(const Laptop& x)
    {
        if(a==x.a)
            return b<x.b;
        return a<x.a;
    }
} lt[100005];

int main()
{
    int n,temp=0;
    cin >> n;
    bool flag=false;
    for(int i=0; i<n; i++)
        cin >> lt[i].a >> lt[i].b;
    sort(lt,lt+n);
    for(int i=1; i<n; i++)
    {
        if(lt[i].b<lt[i-1].b)
        {
            flag=true;
            break;
        }
    }
    if(flag)
        cout << "Happy Alex" << endl;
    else
        cout << "Poor Alex" << endl;
    return 0;
}
