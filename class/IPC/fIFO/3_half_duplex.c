#include"header.h"
main(){
int fd,fs;
char s[20];
mkfifo("f",0644);
mkfifo("f2",0644);
fd=open("f",O_WRONLY);
fs=open("f2",O_RDONLY);
while(1){
printf("Enter Data:");
scanf("%s",s);
write(fd,s,strlen(s)+1);
printf("Waiting for msg...\n");
read(fs,s,sizeof(s));
printf("Data:%s\n",s);
}
}

