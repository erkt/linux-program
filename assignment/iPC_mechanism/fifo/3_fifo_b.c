/*3.process1 will send directory name to process2.
   Process2 after recieving directory name,open directory and count no.of files.and  that  result send back to process1.
*/
#include"header.h"
int main(int argc,char**argv){
	if(argc!=3){
		printf("Usage: ./3a data1 data2..");
		return;
	}
	int fd;
	static int count;
	int d,i;
	DIR *dp;
	struct dirent *p;
	char s[1000];
	mkfifo(argv[1],0644);
	perror("mkfifo");
	mkfifo(argv[2],0644);
	perror("mkfifo");

	if((fd=open(argv[1],O_RDONLY))<0){
		perror("open");
		return;
	}
	read(fd,s,sizeof(s));
	printf("Directory name::%s\n",s);
	close(fd);
	/*i=mkdir(s,0644);
	  if(i<0){
	  perror("mkdir");
	  return;
	  }*/
	dp=opendir(s);
	if(dp==0){
		perror("opendir");
		return;
	}
	while((p=readdir(dp))){
		if(p->d_name[0]!='.'){
			printf("%s\n",p->d_name);
			count++;
		}
	}
	printf("count::%d\n",count);
	if((fd=open(argv[2],O_WRONLY))<0){
		perror("open");
		return;
	}
	write(fd,&count,sizeof(int));
	printf("Done..!!\n");
}

