#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    string s;
    int num=0,cnt=0;
    while(getline(cin,s))
    {
        if(s.substr(0,1)=="+")
            cnt++;
        else if(s.substr(0,1)=="-")
            cnt--;
        else
            num+=cnt*(s.size()-s.find(':')-1);
    }
    cout << num << endl;
    return 0;
}
