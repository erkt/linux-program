/*2. Write a program to execute a command with its arguments given at command line.
i/p :  ./a.out  ls –l
	   ./a.out cal 2011.*/
#include"header.h"
main(int argc,char **argv)
{
	if(argc<2)
	{
	printf("Usage:: ./a.out command_name option.\n");
	return;
	}
	char ch[20];
	int i,j,l;

	if(argc!=2){
	for(j=1,i=0;j<argc;j++,i++){
		for(l=0;argv[j][l];i++,l++)
			ch[i]=argv[j][l];
			ch[i]=' ';
	}
	ch[i]='\0';
	system(ch);}
	else{
	system(argv[1]);
	}

}
