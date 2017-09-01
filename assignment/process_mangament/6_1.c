/*6. Write a program to creat  3 new  jobs , in such a manner that all the 3 new jobs should have common parent.
	x------  bash
	x+1 ---  x
	x+2----  x
	x+3---   x
*/
#include"header.h"
main(int argc,char **argv)
{
int i;
if(argc<2){
printf("Usage::./a.out cmd cmd ....\n");
return;
}
else{
for(i=0;i<argc;i++){
if(fork()==0){
printf("In %d child process pid is %d    and parent id %d\n",i,getpid(),getppid());
break;
}
else{
int r;
while((r=wait(0))!=-1)	
printf("Parent:: pid:: %d and ppid:: %d\n",getpid(),getppid());
}
}

}
}

