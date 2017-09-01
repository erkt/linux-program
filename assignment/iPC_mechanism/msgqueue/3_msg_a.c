/*3.Implement full duplex communication using one message queue?
    Hint :  use different mtypes?*/
#include"header.h"
struct msgbuf{
	long int mtype;
	char data[1000];
}v;
int main(int argc,char **argv){
	if(argc!=3){
		printf("Usage.: ./3a mtype_number_trasmitter mtype_number_receiver..\n");
		return;
	}

	int id;
	if((id=msgget(9,IPC_CREAT|0644))<0){
		perror("msgget");
		return;
	}
	if(fork()){
		char s[1000];
		while(1){
			scanf("%s",s);
			strcpy(v.data,s);
			v.mtype=atoi(argv[1]);
			msgsnd(id,&v,sizeof(v),0);
		}
	}
	else{
		while(1){
			printf("Waiting for Rx....\n");
			msgrcv(id,&v,sizeof(v),atoi(argv[2]),0);
			printf("RX::%s\n",v.data);
		}
	}
}

