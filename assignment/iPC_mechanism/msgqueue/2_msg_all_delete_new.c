#include"header.h"
struct msqid_ds v;
int main()
{
	int j=msgctl(0,MSG_INFO,&v);
	printf("%d\n",j+1);
	int i=0,l=0;

	while(i<=j)
	{
		l=msgctl(i,MSG_STAT,&v);
		printf("%d\n",l);
		i++;
		msgctl(l,IPC_RMID,0);
	}
}
