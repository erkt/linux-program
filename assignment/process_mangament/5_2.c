/*5. Write a program to execute the no of commands from command line
b) using exec()
              Note : no of new process create must be euql to no of cmd given at command line)
*/
#include"header.h"
main(int argc,char **argv)
{
	if(argc<2){
		printf("Usage::./a.out cmd cmd cmd cmd cmd....\n");
		return;
	}
	int i;
	char ch[100];
	for(i=1;i<argc;i++){
		if(fork()==0){
			strcpy(ch,argv[i]);
			printf("%s",ch);
			execlp(ch,argv[i],NULL);
			break;
		}
		else
			while(wait(0)!=-1)
				printf("%s command is perform..\n",argv[i]);
	}
}

