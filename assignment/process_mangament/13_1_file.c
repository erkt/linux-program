//13. Write a program to i/p 2 small(1 to 50) integers from command line and add two interger in child process and print the sum in parent process.
#include"header.h"
void isr(int n){
	FILE *fp=fopen("ans","r");
	if(fp!=0){
		int x;
		fscanf(fp,"%d",&x);
		printf("%d\n",x);
	}
}

int main(int argc,char **argv)
{
	if(argc!=4){
		printf("Usage::./a.out e.g 10 + 20 (NOTE: NUMBER IN BETWEEN 0 to 125)\n");
		return;
	}
	int ret;
	if((ret=fork())==0){
		signal(10,isr);
		pause();
	}
	else{
		int a,b,c;
		FILE *fp=fopen("ans","w");
		fprintf(fp,"%d\n",(atoi(argv[1])+atoi(argv[3])));
		fclose(fp);
		printf("%s + %s::\n",argv[1],argv[3]);
		kill(ret,10);
		wait(0);
	}
	return 0;
}
