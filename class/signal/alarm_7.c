#include"header.h"
void isr(int n)
{
	struct sigaction a;
	printf("ISR..siganl::%d----%d\n",n,getpid());
	sigaction(n,0,&a);
	if(a.sa_handler==SIG_DFL)
		printf("-->default\n");
	else if(a.sa_handler==SIG_IGN)
		printf("-->Ignore..\n");
	else
		printf("-->MY function..\n");
}
main()
{
	struct sigaction a,b;
	int n;
	scanf("%d",&n);

	b.sa_handler=isr;
	sigemptyset(&b.sa_mask);
	b.sa_flags=0;
	sigaction(n,&b,&a);
	if(a.sa_handler==SIG_DFL)
		printf("-->default\n");
	else if(a.sa_handler==SIG_IGN)
		printf("-->Ignore..\n");
	else
		printf("-->MY function..\n");
	while(1);
}
