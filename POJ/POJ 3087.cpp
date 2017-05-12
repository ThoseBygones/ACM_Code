#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

string str1,str2,goal;
queue <char> q1,q2;
map <string,int> m;

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        int n;
        cin >> n;
        cin >> str1 >> str2 >> goal;
        cout << i << " ";
        m.clear();
        while(!q1.empty())
            q1.pop();
        while(!q2.empty())
            q2.pop();
        bool flag=false;
        int cnt=0;
        string mergestr;
        while(1)
        {
            cnt++;
            for(int i=0; i<n; i++)
            {
                q1.push(str1[i]);
                q2.push(str2[i]);
            }
            mergestr.clear();
            for(int i=0; i<n; i++)
            {
                mergestr+=q2.front();
                q2.pop();
                mergestr+=q1.front();
                q1.pop();
            }
            if(!m[mergestr])
                m[mergestr]++;
            else
            {
                flag=true;
                break;
            }
            if(mergestr==goal)
            {
                cout << cnt << endl;
                break;
            }
            str1.clear();
            str2.clear();
            for(int i=0; i<n; i++)
                str1+=mergestr[i];
            for(int i=n; i<2*n; i++)
                str2+=mergestr[i];
        }
        if(flag)
            cout << "-1" << endl;
    }
    return 0;
}
