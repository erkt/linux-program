/*3.Implement full duplex communication using one message queue?
    Hint :  use different mtypes?*/

#include"header.h"
struct msgbuf{
	long int mtype;
	char data[1000];
}v;

int main(int argc,char**argv){
	if(argc!=3){
		printf("Usage.: ./3b mtype_number_recevier mtype_number_transmitter...\n");
		return;
	}

	int id;
	if((id=msgget(9,IPC_CREAT|0644))<0){
		perror("msgget");
		return;
	}

	if(fork()){
		while(1){
			printf("waiting for Tx...\n");
			msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
			printf("TX::%s\n",v.data);
		}
	}
	else{
		char s[1000];
		while(1){
			scanf("%s",s);
			v.mtype=atoi(argv[2]);
			strcpy(v.data,s);
			msgsnd(id,&v,sizeof(v),0);
		}
	}
}
