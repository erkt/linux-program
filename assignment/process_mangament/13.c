//13. Write a program to i/p 2 small(1 to 50) integers from command line and add two interger in child process and print the sum in parent process.
#include"header.h"
main(int argc,char**argv)
{
if(argc!=4){
printf("Usage::./a.out e.g 10 + 20 (NOTE: NUMBER IN BETWEEN 0 to 125)\n");
return;
}
if(fork()==0){
int x=atoi(argv[1])+atoi(argv[3]);
exit(x);
}
else{
int s;
wait(&s);
printf("%d +%d :: %d\n",atoi(argv[1]),atoi(argv[3]),s>>8);
}
}
