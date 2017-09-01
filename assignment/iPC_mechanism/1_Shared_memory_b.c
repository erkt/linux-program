/*Shared Memory: 
1.process1 will send one number  to process2.
   Process2 after recieving one number , then reverse the digits of the given  number  
   send back  results to process1.*/
#include"header.h"
int main(){
	int id,number,*p,*temp,i=0,sum=0,id1;
	struct sembuf v;
	if((id=shmget(10,sizeof(number),IPC_CREAT|0644))<0){
		perror("shmget");
		return;
	}
	printf("Shared memory ID::%d\n",id);
	
	id1=semget(4,2,IPC_CREAT|0644);
	v.sem_num=1;
	v.sem_op=0;
	v.sem_flg=0;
	semop(id1,&v,1);
	

	p=shmat(id,0,0);
	
	semctl(id1,1,SETVAL,1);
	printf("Receving Data::%d\n",*p);
	temp=p;
	number=*temp;
	while(number){
		sum=(sum*10)+(number%10);
		number=number/10;
	}
//	p=shmat(id,0,0);
	*p=sum;
	semctl(id1,0,SETVAL,0);

	printf("Reverse number::%d\n",sum);

}

