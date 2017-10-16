#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string str;
    while(getline(cin,str) && str!="#")
    {
        istringstream sin(str);
        set <string> s;
        string t;
        while(sin >> t)
            s.insert(t);
        cout << s.size() << endl;
    }
    return 0;
}
