/*Shared Memory: 
  1.process1 will send one number  to process2.
  Process2 after recieving one number , then reverse the digits of the given  number  
  send back  results to process1.*/
#include"header.h"
int main(){
	int *p,id,number,id1;
	struct sembuf v;
	if((id=shmget(10,sizeof(number),IPC_CREAT|0644))<0){
		perror("shmget");
		return;
	}
	printf("Shared memory ID::%d\n",id);

	id1=semget(4,1,IPC_CREAT|0644);
	v.sem_num=1;
	v.sem_op=0;
	v.sem_flg=0;



	p=shmat(id,0,0);
	semop(id1,&v,1);	
	
	semctl(id1,0,SETVAL,0);
	printf("Enter the number::");
	scanf("%d",p);
	printf("Done...!\n");
	
	sleep(5);

	semctl(id1,0,SETVAL,1);
	printf("Data::%d\n",*p);
	printf("Done...!\n");

}
