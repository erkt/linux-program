#include"header.h"
void isr(int n)
{
	printf("siganl::%d----%d\n",n,getpid());
}
main()
{
	struct sigaction a;
	int n;
	printf("NUM::");
	scanf("%d",&n);

	a.sa_handler=isr;
	sigemptyset(&a.sa_mask);
	a.sa_flags=0;

	sigaction(n,&a,0);
	while(1);
}
