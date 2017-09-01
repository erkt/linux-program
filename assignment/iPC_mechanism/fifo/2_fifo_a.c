/*1.a)Process1 will send one string to  process2?
   b) process2 recieve the string and store alaphetes in one array and digits(Numeric characters) in another array?
 Ex:  i/p: vector41872india
         o/p : vectorindia  ------->char array          
	      41872  ---------->integer array
2.modify above programm in such a way that sort the data according to descending order.then send 
    back the o/p to process1. 
      O/p:         vtroniiedca  
		87421
 */
#include"header.h"
int main(int argc,char**argv){
	if(argc!=3){
		printf("Usage::./2a data data1\n");
		return;
	}
	int fd,i,j,k,i_array[100];
	char s[100],c_array[100];
	mkfifo(argv[1],0644);
	perror("mkfifo");
	mkfifo(argv[2],0644);
	perror("mkfifo");
	if((fd=open(argv[1],O_WRONLY))<0){
		perror("open");
		return;
	}
	printf("enter the data:");
	scanf("%s",s);
	write(fd,s,strlen(s)+1);
	printf("writing  Done!!\n");
	close(fd);
	if((fd=open(argv[2],O_RDONLY))<0){
		perror("open");
		return;
	}

	read(fd,c_array,sizeof(c_array));
	perror("read");	
	printf("DATA::%s\n",c_array);
	read(fd,i_array,sizeof(i_array));
	for(i=0;i<i_array[0];i++){
		if(i>0)
			//	for(i=0;i<sizeof(i_array);i++){
			printf("DATA INT::%d\n",i_array[i]);

	}

	//j=i_array[0];
	//	printf("%d\n",j);	
	printf("Done!!");
	}

