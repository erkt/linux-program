#include"header.h"
void my_isr(int n){
static int c1=1,c2=1;
if(n==2)
if(c1++==4)
signal(SIGINT,SIG_DFL);
if(n==3)
if(c2++==2)
signal(SIGQUIT,SIG_DFL);
}
main(){
signal(SIGINT,my_isr);
signal(SIGQUIT,my_isr);
printf("PID::%d\n",getpid());
while(1);
}
