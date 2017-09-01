//*#include"header.h"
#include<stdio.h>
main()
{
	if(fork()==0)
	{///child 1
		int r;
		srand(getpid());
		r=rand()%10+1;
		printf("in child one...r::%d,pid::%d\n",r,getpid());
		sleep(r);
		printf("Chile one done!!!.\n");
	}
	else
	{
		if(fork()==0)
		{///child 2
			int r;
			srand(getpid());
			r=rand()%10+1;
			printf("in child two...r::%d,pid::%d\n",r,getpid());
			sleep(r);
			printf("Chile two done!!!.\n");
		}
		else
		{
			if(fork()==0)
			{////child 3
				int r;
				srand(getpid());
				r=rand()%10+1;
				printf("in child three...r::%d,pid::%d\n",r,getpid());
				sleep(r);
				printf("Chile three done!!!.\n");
			}
			else
			{
				int s;
//				s=wait();
				while((s=wait(0 ))!=-1){
					perror("wait");
					printf("IN parent....pid::%d\n",s);
		}	
	printf("\t%d\n",s);
	printf("Done>>>>>\n");
			}
		}
	}
}

