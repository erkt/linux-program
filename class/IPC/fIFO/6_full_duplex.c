#include"header.h"
main(){
	int fd,fs;
	mkfifo("f",0644);
	mkfifo("f1",0644);
	fd=open("f",O_RDONLY);
	fs=open("f1",O_WRONLY);
	if(fork()==0){
		char s[20],c[]="stop";
		while(1){
			printf("Enter Data:");
			scanf("%s",s);
			write(fs,s,strlen(s)+1);
			if(strcmp(s,c)!=-1)
				break;
		}
	}
	else{
		char s[20];
		while(1){
			printf("\nWaiting for msg-2\n");
			read(fd,s,sizeof(s));
			printf("Data:%s\n",s);
		}
	}
}
