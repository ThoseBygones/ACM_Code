//����ⷨ��͵����struct��
//Memory: 2944KB	Time: 3930ms ���е���������ʱ5000ms...��
#include <iostream>
#include <string>
using namespace std;

struct registerSystem
{
    string name;
    int cnt;
} reg[100005];

int main()
{
    int n;
    while(cin >> n)
    {
        int num=0;
        for(int i=1; i<=n; i++)
        {
            bool newName=true;
            string tempName;
            cin >> tempName;
            for(int i=0; i<=num; i++)
            {
                if(tempName==reg[i].name)
                {
                    newName=false;
                    cout << reg[i].name << ++reg[i].cnt << endl;
                    break;
                }
            }
            if(newName)
            {
                reg[num].name=tempName;
                reg[num++].cnt=0;
                cout << "OK" << endl;
            }
        }
    }
    return 0;
}

//������STL����map�Ļ��ǽⷨ����Ȼ��ֱ��ˮ��ȥ...
//Memory: 776 KB	Time: 1496 ms �����ٶ�...����Ī��...��
/*
#include<iostream>
#include<cstring>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

string s;
map <string,int> reg;

int main()
{
	int n;
	cin >> n;
	reg.clear();
	for(int i=0; i<n; i++)
	{
		int flag=0;
		cin >> s;
		int x=reg[s];
		if(reg[s])
		{
			cout << s << x << endl;
		}
		else
		{
			cout << "OK" << endl;
		}
		reg[s]++;
	}
	return 0;
}
*/
