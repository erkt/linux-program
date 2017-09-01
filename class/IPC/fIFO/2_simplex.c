#include"header.h"
main(){
int fd;
char s[20];
mkfifo("f1",0644);
fd=open("f1",O_RDONLY);
while(1){
read(fd,s,sizeof(s));
printf("Data:%s\n",s);
}
}

