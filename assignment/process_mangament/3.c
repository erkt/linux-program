/*3. Observation program :
main()
{
		printf(“before %d and %d\n”,getpid(),getppid());
		fork();
		printf(“1: %d and %d\n”,getpid(),getppid());
		fork();
		printf(“2: %d and %d\n”,getpid(),getppid());
		fork();
		printf(“3: %d and %d\n”,getpid(),getppid());
}
Observe the o/p of this above programme and draw its process generation diagram with its instruction ,processed, parent process id of the new process which is generated and compare with output.*/
#include"header.h"
main()
{
		printf("before %d and %d\n",getpid(),getppid());
		fork();
		printf("1: %d and %d\n",getpid(),getppid());
		fork();
		printf("2: %d and %d\n",getpid(),getppid());
		fork();
		printf("3: %d and %d\n",getpid(),getppid());
}
