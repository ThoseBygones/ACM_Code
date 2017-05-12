#include <iostream>
#include <cstring>
using namespace std;

int mirror[50]={-1,1,35,21,-1,42,-1,-1,8,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,3,-1,-1,24,25,28,-1,26,29,-1,31,-1,-1,-1,2,36,37,38,39,40,41,5};
//               0 1  2  3  4  5  6  7 8  9                       A  B  C  D E  F  G  H  I  J  K  L  M  N  O  P  Q  R S  T  U  V  W  X  Y Z
//              48                     57 58                   65

char in[25];

int main()
{
    while(cin >> in)
    {
        int len=strlen(in);
        bool rev=true,mir=true;
        for(int p1=0,p2=len-1; p1<=p2; p1++,p2--)
        {
            if(in[p1]!=in[p2])
                rev=false;
            if(mirror[in[p1]]==-1 || mirror[in[p2]]==-1)
                mir=false;
            else if(mirror[in[p1]-'0']!=in[p2]-'0')
                mir=false;
        }
        cout << in << " -- ";
        if(!rev && !mir)
            cout << "is not a palindrome.";
        else if(rev && !mir)
            cout << "is a regular palindrome.";
        else if(!rev && mir)
            cout << "is a mirrored string.";
        else if(rev && mir)
            cout << "is a mirrored palindrome.";
        cout << endl << endl;
    }
    return 0;
}
