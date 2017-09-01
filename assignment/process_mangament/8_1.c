/*8. Modify the above program .So that no two jobs have the common parent.
{each job have different parent).
	 x------	bash
	x+1 --- 	x
	x+2----	x+1
	x+3---		x+2
* In the above given prog execute ls, pwd ,cal ,date command by x,x+1,x+2,x+3 respectively.*/
#include"header.h"
main(int argc,char **argv)
{
	if(argc<2){
		printf("Usage::./a.out cmd cmd ...\n");
		return;
	}
	else{
		int i;
		printf("Parent PID: %d and PPID: %d\n",getpid(),getppid());
		for(i=1;i<argc;i++){
			if(fork()==0){
				printf("\n%d process PID:%d and PPID:%d    COMMAND:%s Execute..\n",i,getpid(),getppid(),argv[i]);
				system(argv[i]);
				printf("\n");
			}
			else{
				int r;
				while((r=wait(0))!=-1)
					break;
				break;
			}
		}
	}
}
