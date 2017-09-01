/*1. Write a  program to deliver the alarm signal periodically after (n-1)sec from the last          interrupt.
                    Hint : Start first alarm at 10 sec then next alarm at 9sec so on up to n=0 terminate .
*/
#include"header.h"
int i;
void my_isr(int n){
	printf("%d---%d\n",i,getpid());
	if(i!=0){
		alarm(i--);
		if(i==0)
			signal(SIGALRM,SIG_DFL);
	}
}
main(){
	printf("enter the time in second.");
	scanf("%d",&i);
	signal(SIGALRM,my_isr);
	alarm(i);
	while(1);
}


