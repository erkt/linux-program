/*8. Modify the above program .So that no two jobs have the common parent.
{each job have different parent).
	 x------	bash
	x+1 --- 	x
	x+2----	x+1
	x+3---		x+2
* In the above given prog execute ls, pwd ,cal ,date command by x,x+1,x+2,x+3 respectively.*/
#include"header.h"
main()
{

	if(fork()==0){
		printf("1::PID::%d\tPPID::%d\n\tls\n",getpid(),getppid());
		system("ls");
		if(fork()==0){
			printf("2::PID::%d\tPPID::%d\n\tpwd\n",getpid(),getppid());
			system("pwd");
			if(fork()==0){
				printf("3::PID::%d\tPPID::%d\n\tcal\n",getpid(),getppid());
				system("cal");
				if(fork()==0){
					printf("4::PID::%d\tPPID::%d\n\tdate\n",getpid(),getppid());
					system("date");
				}
			}
		}
	while(1);
	}
	else{
		printf("This is in parent::PID::%d\tPPID::%d\n",getpid(),getppid());
	while(1);
	}
}
