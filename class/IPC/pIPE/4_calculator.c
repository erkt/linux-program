#include"header.h"
typedef struct cal{
	int n,m;
	char c;
}a;
main(){
	int p[2],q[2];
	pipe(p);
	pipe(q);
	//pipe2(p,O_NONBLOCK);
	//pipe2(q,O_NONBLOCK);
	if(fork()){
		a b;
		int ans;
		printf("Enter Data1 and Data2::\n");
		scanf("%d %d",&b.n,&b.m);
		printf("Which opertaion do?\n");
		scanf(" %c",&b.c);
		write(p[1],&b,sizeof(b));
		read(q[0],&ans,sizeof(ans));
		printf("ANS::%d\n",ans);
	}
	else{
		a v;
		int an;
		read(p[0],&v,sizeof(v));
		printf("%d %c %d\n",v.n,v.c,v.m);
		switch(v.c){
			case '+':an=v.n+v.m;write(q[1],&an,sizeof(an));break;
			case '-':an=v.n-v.m;write(q[1],&an,sizeof(an));break;
			case '*':an=v.n*v.m;write(q[1],&an,sizeof(an));break;
			case '/':an=v.n/v.m;write(q[1],&an,sizeof(an));break;
			default: break;
		}
	}
}

