#include"header.h"
int main(){
	int p[2],p1[2];
	pipe(p);
	pipe(p1);
	if(fork()){
		int fd=open("data",O_WRONLY|O_APPEND|O_CREAT ,0644);
		close(1);
		fd=dup(fd);
		srand(getpid());
		int a=rand()%20+1;
		int b=rand()%20+1;
		char ch;
		printf("enter operation\t");
		scanf("%c",&ch); 
		write(p[1],&a,sizeof(int));
		write(p[1],&b,sizeof(int));
		write(p[1],&ch,sizeof(char));
		int ans;
		read(p1[0],&ans,4);
		printf("%d %c %d = %d\n",a,ch,b,ans);
	}
	else{
		int a,b,c;
		char ch;
		read(p[0],&a,4);
		read(p[0],&b,4);
		read(p[0],&ch,1);

		int ans=a+b;
		write(p1[1],&ans,4);
	}
}
