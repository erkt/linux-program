#include"header.h"
main(){
printf("PID::%d\n",getpid());
signal(1,SIG_IGN);
while(1);
}

