////full duplex using msg queue  ////recevier
#include"header.h"
struct g{
	long int mtype;
	char data[100];
};

int main(){
	struct g h;
	int id;
	id=msgget(10,IPC_CREAT|0644);
	if(id<0){
		perror("msgget");
		return;
	}
	if(fork()==0){
		while(1){
			scanf("%s",h.data);
			h.mtype=11;
			//msgsnd(id,&h,sizeof(h),0);
			msgsnd(id,&h,strlen(h.data)+1,0);
			perror("msgsnd");
		}
	}
	else{
		while(1){
			msgrcv(id,&h,sizeof(h.data),9,0);
			printf("TX-DATA : %s\n",h.data);
		}
	}
}
