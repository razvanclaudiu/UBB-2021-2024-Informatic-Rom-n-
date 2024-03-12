#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	printf("Hello world!\n");
	int n, x, i, s=0;
	scanf("%d", &n);
	for(i=0;i<n;i=i+1)
	{
		scanf("%d", &x);
		s = s + x;
	}
	printf("%d",s);

}