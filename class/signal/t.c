#include"header.h"
void isr(int x){
static int c;
printf("%d\n",x);
if (x==2)
c++;
if(c==5)
signal(SIGINT,SIG_DFL);
signal(SIGQUIT,SIG_DFL);
}
int main(){
signal(SIGINT,isr);
signal(SIGQUIT,isr);
//signal(SIGALRM,isr);
//signal(SIGHUP,isr);
//alarm(10);
while(1);
}
