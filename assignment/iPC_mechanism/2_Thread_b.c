/*Threads
1.Implement full duplex communication.*/
#include"header.h"
void* thread_1(void *);
void * thread_2(void *);
char s[100],s1[100];
int main(int argc,char **argv){
if(argc!=3){
printf("Usage:. ./2b Fifo_1_name Fifo_2_name..\n");
return;
}
pthread_t v,v1;
mkfifo(argv[1],IPC_CREAT|0644);
mkfifo(argv[2],IPC_CREAT|0644);
strcpy(s,argv[1]);
strcpy(s1,argv[2]);
pthread_create(&v,NULL,thread_1,NULL);
pthread_create(&v1,NULL,thread_2,NULL);
while(1);
}
void *thread_1(void*p){
char s3[100];
int fd;
fd=open(s,O_RDONLY);
while(1){
read(fd,s3,sizeof(s3));
printf("RX::%s\n",s3);
}
}
void *thread_2(void *p){
char s4[100];
int fd;
fd=open(s1,O_WRONLY);
while(1){
scanf("%s",s4);
write(fd,s4,strlen(s4)+1);
}
}

