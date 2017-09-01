/*1.a)Process1 will send one string to  process2?
  b) process2 recieve the string and store alaphetes in one array and digits(Numeric characters) in another array?
Ex:  i/p: vector41872india
o/p : vectorindia  ------->char array          
41872  ---------->integer array
 */
#include"header.h"
int main(int argc,char **argv){
	if(argc!=2){
		printf("Usage: ./1a data\n");
		return;
	}

	int fd;
	char s[100];
	mkfifo(argv[1],0644);
	perror("mkfifo");
	printf("before...\n");
	if((fd=open(argv[1],O_WRONLY))<0){
		perror("open");
		return;
	}

	printf("after...\n");	
	printf("Enter the string..\n");
	scanf("%s",s);
	write(fd,s,strlen(s)+1);
}
