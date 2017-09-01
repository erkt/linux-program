#include"header.h"
main(){
int fd,fs;
char s[20];
mkfifo("f",0644);
mkfifo("f2",0644);
fd=open("f",O_RDONLY);
fs=open("f2",O_WRONLY);
while(1){
printf("waiting for msg1..\n");
read(fd,s,sizeof(s));
printf("Data:%s\n",s);
printf("Enter Data:");
scanf("%s",s);
write(fs,s,strlen(s)+1);
}
}
