/*7. Modify the above program .So that no two jobs have the common parent.
{each job have different parent).
	 x------	bash
	x+1 --- 	x
	x+2----	x+1
	x+3---		x+2
*/
#include"header.h"
main()
{
	if(fork()==0){
		printf("child 1::PID::%d\tPPID::%d\n",getpid(),getppid());
		if(fork()==0){
			printf("chile 2::PID::%d\tPPID::%d\n",getpid(),getppid());
			if(fork()==0){
				printf("child 3::PID::%d\tPPID::%d\n",getpid(),getppid());
			}
		}
		while(1);
	}
	else{
		printf("This is in parent::PID::%d\tPPID::%d\n",getpid(),getppid());
		while(1);
	}
}
