#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

#define PI acos(-1)
#define ERROR 0.001

double gcd(double a,double b)
{
    if(b>-ERROR && b<ERROR)
        return a;
    else
        return gcd(b,fmod(a,b));
}

int main()
{
    double x1,x2,x3,y1,y2,y3,a,b,c,p,s,r,alpha,beta,gammar,theta;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    p=(a+b+c)/2.0;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    r=(a*b*c)/(4.0*s);
    if(a>c)
        swap(a,c);
    if(b>c)
        swap(b,c);
    alpha=2*asin(a/(2.0*r));
    beta=2*asin(b/(2.0*r));
    gammar=2*PI-alpha-beta;
    theta=gcd(alpha,beta);
    theta=gcd(theta,gammar);
    printf("%.8lf\n",(PI*r*r*sin(theta)/theta));
}
