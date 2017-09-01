/*10. Modify the above program .So that no two jobs have the common parent.
{each job have different parent).
         x------       bash
        x+1 ---        x
        x+2----        x+1
        x+3---         x+2
 In the above program do not use sleep but o/p sequence must be child first & then parent.*/
#include"header.h"
main(int argc,char **argv)
{
	if(argc<2){
		printf("Usage::./a.out child process time type character ...\n");
		return;
	}
	else{
		int i;
		for(i=1;i<argc;i++)
		{
			if(fork()==0){
				printf("\n%d process PID:%d and PPID:%d\n",i,getpid(),getppid());

			}
			else{
				int r;
				while((r=wait(0))!=-1)
					break;
				if(i==argc-1)
					printf("\nParent PID: %d and PPID: %d\n",getpid(),getppid());
				break;
			}
		}
	}
}
