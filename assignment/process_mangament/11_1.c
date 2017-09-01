/*11. Write a program to create a three child process from the common parent use random delay between 1to 10 sec in each child. Use the exit value in such a manner so that parent should know the sequence of the child exits.
      Hint : while(wait(&status)!=-1)
		{
;
		}*/
#include"header.h"
main(int argc,char **argv)
{
if(argc<2){
printf("Usage:./a.out no child process time type ant character..\n");
return;
}
else{
int i;
for(i=1;i<=argc;i++){
if(fork()==0){
int d;
printf("In %d Process..",i);
srand(getpid());
d=(rand()%10)+1;
printf("%d second sleep\n",d);
sleep(d);
printf("Out %d Process..",i);
exit(i);
}
else{
int r,s;
while((r=wait(&s))!=-1)
printf("%d process completed PID:%d and PPID:%d\n",s>>8,r,getppid());
}
}
}
}

