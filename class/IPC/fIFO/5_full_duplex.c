#include"header.h"
main(){
int fd,fs;
mkfifo("f",0644);
mkfifo("f1",0644);
fd=open("f",O_WRONLY);
fs=open("f1",O_RDONLY);
if(fork()){
char s[20],c[]="stop";
while(1){
printf("Enter Data:");
scanf("%s",s);
write(fd,s,strlen(s)+1);
if(strcmp(s,c)!=-1)
break;
}
}
else{
char s[20];
while(1){
printf("\nwaiting for msg-1\n");
read(fs,s,sizeof(s));
printf("Data:%s\n",s);
}
}
}
