#include"header.h"
void isr(int n)
{
printf("siganl::%d----%d\n",n,getpid());
}
main()
{
struct sigaction a;
int n;
scanf("%d",&n);

sigaction(n,0,&a);
if(a.sa_handler==SIG_DFL)
printf("-->default\t");
else if(a.sa_handler==SIG_IGN)
printf("-->Ignore..\t");
else
printf("-->MY function..\t");

}
