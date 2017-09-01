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
		int N_File,H_link;
	}output;
}V1;
int main(int argc,char **argv){
	if(argc!=3){
		printf("Usage.: ./1a keynumber directory_name..\n");
		return;
	}
	int md;
	struct msgbuf V;
	if((md=msgget(6,IPC_CREAT|0644))<0){
		perror("msgget");
		return;
	}
	strcpy(V.d,argv[2]);
	printf("This Directory send to process-2::%s\n",V.d);
	V.mtype=atoi(argv[1]);
	msgsnd(md,&V,strlen(V.d)+1,0);
	perror("msgsnd");
	sleep(5);
	msgrcv(md,&V1,sizeof(V1.output),11,0);
	perror("msgrcv");
	printf(" %d No of files  ,  %d No of Hardlinks in '  %s  ' directory\n",V1.output.N_File,V1.output.H_link,argv[2]);
}
