#include"header.h"
main(){
	void (*p)(int);
	int num;
	while(1){
	printf("Enter the number:");
	scanf("%d",&num);
	signal(2,SIG_IGN);
	p=signal(num,SIG_IGN);
	signal(num,p);
	if(p==SIG_DFL)
		printf("DEFAULT..\n");
	else if(p==SIG_IGN)
		printf("IGNORE..\n");
	else
		printf("MY FUNCTION..\n");
	}
	while(1);
}
