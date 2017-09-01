#include"header.h"
main()
{
if(fork()==0)
{
printf("IN child....\n");
sleep(155555);
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
if(WIFEXITED(s))
printf("Normal:%d\n",WEXITSTATUS(s));
else if(WIFSIGNALED(s))
printf("siganl:%d\n",WTERMSIG(s));
}
}
