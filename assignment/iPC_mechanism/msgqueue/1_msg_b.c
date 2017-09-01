/*1.process1 will send directory name to process2.
   Process2 after recieving directory name,open directory ,send back no.of files  and no.of hardlinks  
    to process1.
*/
#include"header.h"
struct msgbuf{
	long int mtype;
	char d[100];
};
struct msgbuf1{
	long int mtype;
	struct out{
	int N_file,H_link;
	}output;
}V1;
int main(int argc,char **argv){
	if(argc!=2){
		printf("Usage.: ./1b keynumber..\n");
		return;
	}
	int md;
	DIR *fd;
	struct dirent *p;
	struct msgbuf V;
	struct stat x;
	if((md=msgget(6,IPC_CREAT|0644))<0){
		perror("msgget");
		return;
	}
	msgrcv(md,&V,sizeof(V),atoi(argv[1]),0);
	perror("msgrcv");
	printf("DIRECTORY::%s\n",V.d);

	fd=opendir(V.d);
	if(fd==0){
		perror("opendir");
		return;
	}
	V1.output.N_file=0;
	while((p=readdir(fd))){
		if(p->d_name[0]!='.'){
			V1.output.N_file++;
		}
	}
	if((stat(V.d,&x))<0){
	perror("stat");
	return;
	}	
	V1.output.H_link=x.st_nlink;
	V1.mtype=11;
	msgsnd(md,&V1,sizeof(V1.output),0);
	perror("msgsnd");
	printf("Done...\n");
}
