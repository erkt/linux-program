/*6. Write a program to creat  3 new  jobs , in such a manner that all the 3 new jobs should have common parent.
	x------  bash
	x+1 ---  x
	x+2----  x
	x+3---   x
*/
#include"header.h"
main()
{
	if(fork()==0)
	{
		printf("In first child process pid is %d    and parent id %d\n",getpid(),getppid());
	}
	else
	{
		if(fork()==0)
		{
			printf("In second child process pid is %d    and parent id %d\n",getpid(),getppid());
		}
		else
		{
			if(fork()==0)
			{
				printf("In three child process pid is %d    and parent id %d\n",getpid(),getppid());
			}
			else
			{
				printf("Parent process pid is %d and parent pid is %d\n",getpid(),getppid());
				while(1);
			}
		}
	}
}
