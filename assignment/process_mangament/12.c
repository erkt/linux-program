/*12. Write a program to create a three child process from the common parent use random delay between 1to 10 sec in each child. Use the exit value in such a manner so that parent should know the sequence of the child exits.
      Hint : while(wait(&status)!=-1)
		{
;
		}
 Modify the above program so that parent will wait uptp child -2 exit.sp after child-2 parent will laso exit and another child become may be in Zombie or Orphan.*/
#include"header.h"
main()
{
	if(fork()==0){
		int d;
		printf("CHILD 1 process start..\n");
		srand(getpid());
		d=(rand()%10)+1;
		printf("%ds C1 PID:%d\n",d,getpid());
		sleep(d);
		exit(1);
	}
	else{
		if(fork()==0){
			int d;
			printf("CHILD 2 process start..\n");
			srand(getpid());
			d=(rand()%10)+1;
			printf("%ds C2 PID:%d\n",d,getpid());
			sleep(d);
			exit(2);
		}
		else{
			if(fork()==0){
				int d;
				printf("CHILD 3 process start..\n");
				srand(getpid());
				d=(rand()%10)+1;
				printf("%ds C3 PID:%d\n",d,getpid());
				sleep(d);
				exit(3);
			}
			else{
				int r,s,i=0;
				while((r=wait(&s))!=-1){
					printf("%d process completed..and it's PID:%d\n",s>>8,r);
					i++;
					if(i==2)
					break;
				}
			}
		}
	}
}
