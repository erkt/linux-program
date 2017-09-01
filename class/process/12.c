#include"header.h"
main()
{
if(fork()==0)
{
printf("IN child....\n");
sleep(10);
printf("After sleep\n");
exit(1);
}
else
{
int s;
printf("in parent....\n");
wait(&s);
printf("come out of wait state....\n");
printf("in parentas after s::%d\n",s);
}
}
