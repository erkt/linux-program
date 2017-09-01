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
	int fd,i_array[100],i,j,k,l;
	char s[100],c_array[100] ;
	mkfifo(argv[1],0644);
	perror("mkfifo");
	mkfifo(argv[2],0644);
	perror("mkfifo");

	if((fd=open(argv[1],O_RDONLY))<0){
		perror("open");
		return;
	}
	printf("reading...........\n");
	read(fd,s,sizeof(s));
	close(fd);
	for(i=0,l=1,k=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9')
			i_array[l++]=s[i]-48;
		else
			c_array[k++]=s[i];
	}
	c_array[k]='\0';
	for(i=1;i<l;i++){
		for(j=1;j<l-i;j++){
			if(i_array[j]<i_array[j+1]){
				int temp=i_array[j];
				i_array[j]=i_array[j+1];
				i_array[j+1]=temp;
			}
		}
	}
	i_array[0]=l;
	for(i=0;i<k-1;i++){
		for(j=0;j<k-i-1;j++){
			if(c_array[j]<c_array[j+1]){
				char temp=c_array[j];
				c_array[j]=c_array[j+1];
				c_array[j+1]=temp;
			}
		}
	}
	for(i=1;i<l;i++)
		printf("%d",i_array[i]);
	printf("\nAbove integer array\nbelow character array \n");
	printf("%s\n",c_array);
	if((fd=open(argv[2],O_WRONLY))<0){
		perror("open");
		return;
	}

	write(fd,c_array,strlen(c_array)+1);
	//for(i=0;i<l;i++)	
	write(fd,i_array,sizeof(int)*l);
	

	printf("Done!!\n");
}

