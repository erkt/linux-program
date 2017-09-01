/*3.process1 will send directory name to process2.
   Process2 after recieving directory name,open directory and count no.of files.and  that  result send back to process1.
*/
#include"header.h"
int main(int argc,char**argv){
if(argc!=4){
printf("Usage: ./3a data1 data2 Directory..");
return;
}
int fd;
int d;
mkfifo(argv[1],0644);
perror("mkfifo");
mkfifo(argv[2],0644);
perror("mkfifo");

if((fd=open(argv[1],O_WRONLY))<0){
perror("open");
return;
}
write(fd,argv[3],strlen(argv[3])+1);
close(fd);

if((fd=open(argv[2],O_RDONLY))<0){
perror("open");
return;
}
read(fd,&d,sizeof(int));
printf("%d No of File in %s directory..\n ",d,argv[3]);
}

