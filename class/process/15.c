#include"header.h"
main()
{
	int a[4];
	if((a[0]=fork())==0)
	{
		int r;
		srand(getpid());
		r=rand()%10+1;
		printf("in child one...r::%d,pid::%d\n",r,getpid());
		sleep(r);
	}
	else
	{
		if((a[1]=fork())==0)
		{
			int r;
			srand(getpid());
			r=rand()%10+1;
			printf("in child two...r::%d,pid::%d\n",r,getpid());
			sleep(r);
		}
		else
		{
			if((a[2]=fork())==0)
			{
				int r;
				srand(getpid());
				r=rand()%10+1;
				printf("in child three...r::%d,pid::%d\n",r,getpid());
				sleep(r);
			}
			else
			{
				int r;
				while((r=wait(0))!=-1){
					if(r==a[0])
						printf("Chile one done!!!.\n");
					else if(r==a[1])
						printf("Chile two done!!!.\n");
					else if(r==a[2])
						printf("Chile three done!!!.\n");
					printf("IN parent....pid::%d\n",r);
				}
				printf("Done>>>>>\n");
			}
		}
	}
}

