#include"header.h"
struct msgbuf{
	long int mtype;
	int n;
}v;

int main(int argc,char **argv){
	if(argc!=2){
		printf("\n\tUsage:. ./msg_creation_dummy how_many_msg_queue_will_be_created...\n\n");
		return;
	}
	int id,i,j;
		id=msgget(2,IPC_CREAT|0644);
/*	srand(getpid());
	int id,i,j=(rand()%100);
	for(i=1;i<=atoi(argv[1]);i++,j++){
		if((id=msgget(j,IPC_CREAT|0644))<0){
			perror("msgget");
			return;
		}
	}
*/	printf("\n\t%d msg queue created..\n\n",i-1);
}

