#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

string str;

int main()
{
    int cnt=0;
    while(cin >> str)
    {
        int key=0;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]=='D' || str[i]=='d')
                key++;
            else if((str[i]=='O' || str[i]=='o') && key==1)
                key++;
            else if((str[i]=='G' || str[i]=='g') && key==2)
                key++;
            else if((str[i]=='E' || str[i]=='e') && key==3)
            {
                key=0;
                cnt++;
            }
            else
                key=0;
        }
    }
    cout << cnt << endl;
    return 0;
}
