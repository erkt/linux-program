//2.WAP to delete all message queues?
#include"header.h"
struct msqid_ds v;
int main(){
	int j,l=0;
	int k=msgctl(0,MSG_INFO,&v);/////number of msg queue in that kernel array starting form 0  to onward(if created msg que =10 it will return 9)
	while(l<=k){
		j=msgctl(l,MSG_STAT,&v);/////i'm getting msgid using index of kernel array and array starting from 0 onward
		printf("%d\n",j);
		int k=msgctl(j,IPC_RMID,0);////removig msg queue using that msg id
		if(k<0){
			printf("\n\tMessage Queue is a EMPTY...!!!!\n\n");
			return;
		}
		l++;
/*		printf("%d  ",j);
		if((j%10)==0)
		printf("\n");
*/	}
	printf("\n\tTotal Number Of Deleted message in queue::%d\n\n",k+1);	
}
