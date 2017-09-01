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
printf("Child goes to Zombie process...\n");
while(1);
}
}


