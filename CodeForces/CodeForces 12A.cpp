#include <iostream>
using namespace std;

char mat[3][3];

int main()
{
    for(int i=0; i<3; i++)
        cin >> mat[i];
    if(mat[0][0]==mat[2][2] && mat[0][1]==mat[2][1] && mat[0][2]==mat[2][0] && mat[1][0]==mat[1][2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
