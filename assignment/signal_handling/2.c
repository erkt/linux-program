/*2. Create a watch dog timer in parent which should watch T.A.T of its child and terminate the  child.
                  Condition:  The child have random delay(1-10 sec)
                  If the child take more than 5 sec then parent terminate it.//////T.A.T==turn around time
                  Hint : fork(),sleep?(),kill(),alarm().*/
#include"header.h"
static int k; 
int pid;
void ISR(int k){
	if(k==100){
		printf("CHILD killed\n");
		kill(pid,9);
		perror("kill");
	}
	printf("Parent continue bcoz child is teminated before 5 sec....\nDone!!\n");
}
int main(){
	signal(SIGALRM,ISR);
	srand(getpid());
	k=rand()%10;
	if((pid=fork()))
	{//parent
		printf("child pid in parent:%d\n",pid);
		printf("in parent %d\n",getpid());
		printf("time:%d\n",k);
		alarm(k);
		if(k<=5)
			while(1);
		else
			ISR(100);


	}
	else{//child
		printf("in child before sleep..%d.\n",getpid());
		sleep(k);
		printf("After sleep....%d sec\n",k);
	}
}
