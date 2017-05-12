#include <iostream>
using namespace std;

int n,bowl,plate;
int dish[1005];

int main()
{
    cin >> n >> bowl >> plate;
    for(int i=1; i<=n; i++)
        cin >> dish[i];
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(dish[i]==1)
        {
            if(bowl)
                bowl--;
            else
                cnt++;
        }
        if(dish[i]==2)
        {
            if(plate)
                plate--;
            else if(bowl)
                bowl--;
            else
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
