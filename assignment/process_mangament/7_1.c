/*7. Modify the above program .So that no two jobs have the common parent.
{each job have different parent).
	 x------	bash
	x+1 --- 	x
	x+2----	x+1
	x+3---		x+2
*/
#include"header.h"
main(int argc,char **argv)
{
if(argc<2){
printf("Usage::./a.out any character you want to creat process time.\n");
return;
}
int i;
printf("Parent PID : %d and PPID : %d\n",getpid(),getppid());
for(i=0;i<argc;i++){
	if(fork()==0){
		printf("%d process PID : %d and PPID : %d\n",i,getpid(),getppid());
	}
	else{
		int i;
		while((i=wait(0))!=-1)
			break;
		break;
	}
}
}
