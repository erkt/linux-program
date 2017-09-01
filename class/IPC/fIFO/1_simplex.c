#include"header.h"
main(){
int fd;
char s[20];
mkfifo("f1",0644);
fd=open("f1",O_WRONLY);
while(1){
printf("Enter Data:");
scanf("%s",s);
write(fd,s,strlen(s)+1);
}
}

