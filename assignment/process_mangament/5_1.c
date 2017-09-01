/*5. Write a program to execute the no of commands from command line
a) using system( )
*/
#include"header.h"
main(int argc,char **argv)
{
if(argc<2){
printf("Usage::./a.out cmd cmd cmd cmd cmd....\n");
return;
}
int i=0;
char ch[100];
for(i=1;i<argc;i++){
sleep(1);
system(strcpy(ch,argv[i]));sleep(1);}
}


