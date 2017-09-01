#include"header.h"
main()
{
if(fork()==0)
{
printf("in child pid::%d ppid::%d\n",getpid(),getppid());
sleep(10);
printf("in child after sleep pid::%d ppid::%d\n",getpid(),getppid());
}
else
{
sleep(5);
printf("Child goes to orphan process...\n");
}
}


