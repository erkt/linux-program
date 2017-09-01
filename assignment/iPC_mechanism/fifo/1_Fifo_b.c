/*1.a)Process1 will send one string to  process2?
   b) process2 recieve the string and store alaphetes in one array and digits(Numeric characters) in another array?
 Ex:  i/p: vector41872india
         o/p : vectorindia  ------->char array          
	      41872  ---------->integer array
*/
#include"header.h"
int main(int argc,char **argv){
	if(argc!=2){
		printf("Usage: ./1b data\n");
		return;
	}
	int fd,k,j,l,i_array[100];
	char s[100],c_array[100];
	mkfifo(argv[1],0644);
	perror("mkfifo");
	printf("before...\n");
	if((fd=open(argv[1],O_RDONLY))<0){
		perror("open");
		return;
	}
	printf("after...\n");	
	read(fd,s,sizeof(s));
	for(k=j=l=0;s[k];k++){
		if(s[k]>='0'&&s[k]<='9')
			i_array[l++]=(s[k]-48);
		else
			c_array[j++]=s[k];
	}
	i_array[l]=c_array[j]='\0';
	printf("Char::%d---Int::%d\n",j,l);
	for(k=0;k<l;k++)
	printf("%d",i_array[k]);
	printf("\n%s\n",c_array);
}
