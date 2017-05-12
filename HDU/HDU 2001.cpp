#include<stdio.h>
#include<math.h>
int main()
{
	double x1,y1,x2,y2,d;
	while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		printf("%.2lf\n",d);
	}
	return 0;
}
