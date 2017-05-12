#include<iostream>
#include<algorithm>
using namespace std;

int cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int side[5];
    for(int i=0; i<4; i++)
        cin >> side[i];
    sort(side,side+4,cmp);
    if(side[0]>side[1]+side[2])
    {
        if(side[1]>side[2]+side[3])
            cout << "IMPOSSIBLE" << endl;
        else if(side[1]==side[2]+side[3])
            cout << "SEGMENT" << endl;
        else
            cout << "TRIANGLE" << endl;
    }
    else if(side[0]==side[1]+side[2])
    {
        if(side[1]<side[2]+side[3])
            cout << "TRIANGLE" << endl;
        else
            cout << "SEGMENT" << endl;
    }
    else
        cout << "TRIANGLE" << endl;
    return 0;
}
