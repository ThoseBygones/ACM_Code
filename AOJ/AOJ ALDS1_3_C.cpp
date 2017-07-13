#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string op;
    list <int> l;
    for(int i=1; i<=n; i++)
    {
        cin >> op;
        if(op=="insert")
        {
            int val;
            cin >> val;
            l.push_front(val);
        }
        else if(op=="delete")
        {
            int val;
            cin >> val;
            for(list<int>::iterator it=l.begin(); it!=l.end(); it++)
            {
                if(*it==val)
                {
                    l.erase(it);
                    break;
                }
            }
        }
        else if(op=="deleteFirst")
            l.pop_front();
        else if(op=="deleteLast")
            l.pop_back();
    }
    bool flag=true;
    for(list<int>::iterator it=l.begin(); it!=l.end(); it++)
    {
        if(flag)
        {
            cout << *it;
            flag=false;
        }
        else
            cout << " " << *it;
    }
    cout << endl;
    return 0;
}
