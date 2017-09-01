#include"header.h"
void isr(int n)
{
printf("siganl::%d----%d\n",n,getpid());
sleep(3);
printf("After sleep..\n");
}
main()
{
struct sigaction a;
int n;
printf("NUM::");
scanf("%d",&n);

a.sa_handler=isr;
sigemptyset(&a.sa_mask);
a.sa_flags=SA_NODEFER;

sigaction(n,&a,0);
while(1);
}
