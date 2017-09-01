#include"header.h"
void my_isr(int n){
printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}
main(){
signal(SIGALRM,my_isr);
printf("------------------------------\n");
alarm(5);
printf("####################################\n");
while(1);
}
