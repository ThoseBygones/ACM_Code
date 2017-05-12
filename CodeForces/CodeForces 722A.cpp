#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int f,hh,mm;
    char c;
    cin >> f >> hh >> c >> mm;
    if(mm>=60)
        mm%=10;
    if(hh==24 || hh>f)
        hh%=10;
    if(f==12 && hh==0)
        hh=10;
    printf("%02d:%02d\n",hh,mm);
    return 0;
}
