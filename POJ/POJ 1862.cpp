#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define MAXN 105

int main()
{
    int n;
    scanf("%d",&n);
    priority_queue <double> pq;
    for(int i=0; i<n; i++)
    {
        double w;
        scanf("%lf",&w);
        pq.push(w);
    }
    while(pq.size()>1)
    {
        double a=pq.top();
        pq.pop();
        double b=pq.top();
        pq.pop();
        double c=2*sqrt(a*b);
        pq.push(c);
    }
    printf("%.3f\n",pq.top());
    return 0;
}
