/*6. Write a program to install ISR(handler) for SIGINT and SIGQUIT . Restore the SIGINT to  default after 3 times occurrence.SIGQUIT to default after 5 times occurrence.*/
#include"header.h"
int i=0,q=0;
void isr(int x){
	if(SIGINT==x){
		printf("In ISR..Due to SIGINT Signal..!!!\n");
		i++;
	}
	if(SIGQUIT==x){
		printf("In ISR..Due to SIGQUIT Signal..!!!\n");
		q++;
	}
	if(i==3){
		signal (SIGINT,SIG_DFL);
		printf("This is your last chance further if you give ' SIGINT ' signal it will terminating....\n");
	}
	if(q==5){
		signal(SIGQUIT,SIG_DFL);
		printf("This is your last chance further if you give ' SIGQUIT ' signal it will terminating....\n");
	}
}

int main(){
	printf("In main...\n");
	signal(SIGINT,isr);
	signal(SIGQUIT,isr);
	while(1);
}
