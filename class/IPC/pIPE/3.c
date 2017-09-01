#include"header.h"
main(){
	int p[2],q[2];
	pipe(p);
	pipe(q);
	if(fork()){
		char s[20];
		printf("Enter Data:");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
		read(q[0],s,sizeof(s));
		printf("After Data::%s\n",s);
	}
	else{
		char s1[20];
		int i;
		read(p[0],s1,sizeof(s1));
		for(i=0;s1[i];i++)
			if(s1[i]>='a'&&s1[i]<='z')
				s1[i]=s1[i]-32;
		write(q[1],s1,strlen(s1)+1);
	}
}

