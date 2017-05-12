#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string weekName[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main()
{
    string name1,name2;
    cin >> name1 >> name2;
    int first,second;
    for(int i=0; i<7; i++)
    {
        if(name1==weekName[i])
            first=i+1;
        if(name2==weekName[i])
            second=i+1;
    }
    int temp;
    temp=second-first;
    if(first>second)
        temp=second-first+7;
    if(temp==0 || temp==2 || temp==3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
