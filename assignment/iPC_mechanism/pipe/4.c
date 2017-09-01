#include"header.h"
int src(char *,char *);
int main(int argc,char **argv){
	int p[2];
	int p1[2];
	pipe(p);
	pipe(p1);

	if(fork()==0){
		char s[100]={},s1[100]={};
		read(p[0],s,sizeof(s));
		read(p[0],s1,sizeof(s1));
		int n= src(s,s1);
		if(n!=0){
			write(p1[1],&n,4);
			printf("%d\n",n);
		}
		else
			printf("---");
	}
	else{
		write(p[1],argv[1],strlen(argv[1]));
		sleep(1);
		write(p[1],argv[2],strlen(argv[2]));
		int n;
		read(p1[0],&n,4);
		printf("::%d\n",n);
	}
}
int src(char *a,char *b){
	int i=0;
	static int n;
	DIR *dp;
	struct dirent *q;
//	struct stat v;
	char s[100],s1[100];
	strcpy(s1,b);
	dp = opendir(s1);
	while(q=readdir(dp)){
		if(q->d_name[0]!='.')
			if(q->d_type==DT_DIR){
				strcpy(s,s1);
				strcat(s,q->d_name);
				strcat(s,"/");
				src(a,s);
			}
			else{
				if(!(strcmp(a,q->d_name)))
					n++;
			}
	}
	return n;
}

