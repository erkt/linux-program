/*4. Write a program to remove the zombie. 
Hint : Use SIGCHLD  &signal( ).*/
#include"header.h"
void ISR(int k){
	wait(0);
}
int main(){
	if(fork()){
		printf("Parent:%d\n",getpid());
		signal(SIGCHLD,ISR);
		while(1);
	}
	else{
		printf("Child:%d\n",getpid());
		sleep(3);
	}
}

