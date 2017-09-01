/*3. Create a function named “find-isr”,which when calling by passing an interrupt number then it  should inform the action of that signal in current program.
  Signal action----defaulted
  o/p->Ignore
  userdefine.
Hint : use signal( ) function to return value.	
 */
#include"header.h"
void find_isr(int x);
int main(int argc,char **argv){
	if(argc!=2){
		printf("Usage: ./a.out interrupt_number\n");
		return;
	}
	printf("before getting interupt...\n");
	int x=atoi(argv[1]);
	int ret=signal(x,find_isr);
	printf("After interupt..\n");


	while(1);
}
void find_isr(int x){
	printf("in Find isr.\n");
	printf("%d\n",x);
}
