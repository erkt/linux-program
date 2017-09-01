/*Threads
1.Implement full duplex communication.*/
#include"header.h"
void* therad_1(void *);
void * therad_2(void *);
char s[100],s1[100];
int main(int argc,char **argv){
if(argc!=3){
printf("Usage:. ./1a Fifo_1_name Fifo_2_name..\n");
return;
}
pthread_t v,v1;
strcpy(s,argv[1]);
strcpy(s1,argv[2]);
mkfifo(argv[1],IPC_CREAT|0644);
mkfifo(argv[2],IPC_CREAT|0644);
pthread_create(&v,NULL,therad_1,NULL);
pthread_create(&v1,NULL,therad_2,NULL);
while(1);
}

void *therad_1(void *p){
char s3[20];
int fd;
fd=open(s,O_WRONLY);
while(1){
scanf("%s",s3);
write(fd,s3,strlen(s3)+1);
}
}
void *therad_2(void *p){
char s4[20];
int fd;
fd=open(s1,O_RDONLY);
while(1){
read(fd,s4,sizeof(s4));
printf("Tx::%s\n",s4);
}
}
