#include <iostream>
//#include <cstdio>
#include <string>
#include <algorithm>
#define MAXN 10005
using namespace std;

struct piotr
{
    int id;
    int pos;
    int dir;
    bool operator < (const piotr& p)const
    {
        return pos<p.pos;
    }
} start[MAXN],over[MAXN];

string dirName[5]= {"L","Turning","R"};
int order[MAXN];

int main()
{
    int T,kase=1;
    int l,t,n;
    cin >> T;
    while(T--)
    {
        cin >> l >> t >> n;
        cout << "Case #" << kase++ << ":" << endl;
        for(int i=0; i<n; i++)
        {
            int tempPos,tempD;
            char tempDir;
            cin >> tempPos >> tempDir;
            if(tempDir=='L')
                tempD=-1;
            else
                tempD=1;
            start[i].id=i;
            start[i].pos=tempPos;
            start[i].dir=tempD;
            over[i].id=0;
            over[i].pos=tempPos+t*tempD;
            over[i].dir=tempD;
        }
        sort(start,start+n);
        for(int i=0; i<n; i++)
            order[start[i].id]=i;  //无论怎么碰撞，蚂蚁的相对位置不变；
        sort(over,over+n);
        for(int i=0; i<n-1; i++)
        {
            if(over[i].pos==over[i+1].pos)
                over[i].dir=over[i+1].dir=0;
        }
        for(int i=0; i<n; i++)
        {
            int temp=order[i];
            if(over[temp].pos>=0 && over[temp].pos<=l)
                cout << over[temp].pos << " " << dirName[over[temp].dir+1] << endl;
            else
                cout << "Fell off" << endl;
        }
        cout << endl;
    }
    return 0;
}
