#include<stdio.h>
int main()
{
	char c1,c2,c3,x;
	while(scanf("%c%c%c",&c1,&c2,&c3)!=EOF)
	{
		if(c1>c2) x=c1,c1=c2,c2=x;
		if(c1>c3) x=c1,c1=c3,c3=x;
		if(c2>c3) x=c2,c2=c3,c3=x;
		printf("%c %c %c\n",c1,c2,c3);
		getchar();
	}
	return 0;
}
	


