#include"header.h"
main(){
	int p[2];
	pipe(p);
	printf("p[0]:Read end::%d\n",p[0]);
	printf("p[1]:Write end::%d\n",p[1]);
	if(fork()){
		char s[20];
		printf("Enter Data::");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
		sleep(1);////////sleep not use in many time data transfer through pipe..
		wait(0);///loose job concerncy here 
		read(p[0],s,sizeof(s));
		printf("After Modification data will be:%s\n",s);
	}
	else{
		char s1[20];
		int i;
		printf("Before modification..\n");
		read(p[0],s1,sizeof(s1));
		for(i=0;s1[i];i++)
			if(s1[i]>='a'&&s1[i]<='z')
				s1[i]=s1[i]-32;
		write(p[1],s1,sizeof(s1));
	}
}

