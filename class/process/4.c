/////random number
#include"header.h"
main()
{
	int a[5],i;
	unsigned int k;
	float f[5];
	for(i=0;i<5;a[i++]=rand());
	for(i=0;i<5;printf("%d  ",a[i++]));
	printf("\n");
///////////number between 0.25to 0.75///////
	k= getpid();
	srand(k);
	for(i=0;i<5;i++)
		f[i]=(((float)((rand()%50+25))/100));
	for(i=0;i<5;printf("%f  ",f[i++]));
	printf("\n");
}
