/*4). Write a program to pass num of commands each seperated by delimiter(,) through command line.
  I/p :   ./a.out   ls,pwd,cal,date*/
#include"header.h"
main(int argc,char**argv)
{
	if(argc!=2)
	{
		printf("Usage:: ./a.out cmd,cmd,cmd,cmd....\n");
		return;
	}
	int i,j;
	char ch[100];

	for(i=0,j=0;argv[1][i];i++)
	{
		if(argv[1][i]!=',')
			ch[j++]=argv[1][i];
		if(argv[1][i]==','||argv[1][i+1]=='\0'){
			ch[j]='\0';
			system(ch);
			j=0;
		}

	}
}
