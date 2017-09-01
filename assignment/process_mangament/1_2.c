/*1. Write a program to execute ls , pwd & cal sequentially
  	       b) Using exec( )
		Hint : use fork().
*/

#include"header.h"
main()
{
	if(fork()==0)
		execl("/bin/ls","ls ",NULL);
	else{
		wait(0);
		printf("ls done!!!!\n");
		if(fork()==0)
			execl("/bin/pwd","pwd ",NULL);
		else{
			wait(0);
			printf("pwd done!!!!\n");
			if(fork()==0)
				execlp("cal"," ",NULL);
			else{
				wait(0);
				printf("cal done!!!!\n");
				printf("Done..\n");
			}
		}
	}
}
