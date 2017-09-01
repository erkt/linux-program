#include"header.h"
#include<string.h>
int main(int argc,char **argv){
if(argc!=2){
printf("Usage:. ./a.out  filename \n");
return; 
}
int i,j;
close(1);
int fd=open(argv[1],O_WRONLY|O_APPEND|O_CREAT,0644);
perror("open");
fd=dup(fd);
while(1){
srand(getpid());
i=rand()%20;
srand(getpid()+1);
j=rand()%20;

printf("%d + %d\n",i,j);
}
}
