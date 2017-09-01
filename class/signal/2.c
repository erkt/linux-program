#include"header.h"
void my_isr(int n){
printf("In Isr.....\n");
}
main()
{
signal(SIGINT,my_isr);
printf("hello...\n");
while(1);
}
